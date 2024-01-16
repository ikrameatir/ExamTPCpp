import numpy as np


int_to_char = {
    0: 'u',
    1: 'r',
    2: 'd',
    3: 'l'
}

policy_one_step_look_ahead = {
    0: [-1, 0],
    1: [0, 1],
    2: [1, 0],
    3: [0, -1]
}

def policy_int_to_char(pi, n):
    pi_char = ['']

    for i in range(n):
        for j in range(n):
            if i == 0 and j == 0 or i == n - 1 and j == n - 1:
                continue

            pi_char.append(int_to_char[pi[i, j]])

    pi_char.append('')
    return np.asarray(pi_char).reshape(n, n)



def policy_evaluation(n, pi, v, Gamma, threshhold):
    while True:
        delta = 0
        for i in range(n):
            for j in range(n):
                if (i == 0 and j == 0) or (i == n - 1 and j == n - 1):
                    continue

                old_v = v[i, j]
                new_v = 0
                for action in range(4):
                    next_i, next_j = i + policy_one_step_look_ahead[action][0], j + policy_one_step_look_ahead[action][1]
                    next_i = max(0, min(n - 1, next_i))
                    next_j = max(0, min(n - 1, next_j))
                    new_v += pi[i, j] == action * (-1 + Gamma * v[next_i, next_j])

                v[i, j] = new_v
                delta = max(delta, abs(old_v - v[i, j]))

        if delta < threshhold:
            break

    return v



def policy_improvement(n, pi, v, Gamma):
    new_pi = np.zeros_like(pi)
    pi_stable = True

    for i in range(n):
        for j in range(n):
            if (i == 0 and j == 0) or (i == n - 1 and j == n - 1):
                continue

            old_action = pi[i, j]
            action_values = []
            for action in range(4):
                next_i, next_j = i + policy_one_step_look_ahead[action][0], j + policy_one_step_look_ahead[action][1]
                next_i = max(0, min(n - 1, next_i))
                next_j = max(0, min(n - 1, next_j))
                action_values.append(-1 + Gamma * v[next_i, next_j])

            new_pi[i, j] = np.argmax(action_values)

            if old_action != new_pi[i, j]:
                pi_stable = False

    return new_pi, pi_stable



def policy_initialization(n):
    return np.random.randint(0, 4, size=(n, n))



def policy_iteration(n, Gamma, threshhold):
    pi = policy_initialization(n=n)
    v = np.zeros(shape=(n, n))

    while True:
        v = policy_evaluation(n=n, v=v, pi=pi, threshhold=threshhold, Gamma=Gamma)
        new_pi, pi_stable = policy_improvement(n=n, pi=pi, v=v, Gamma=Gamma)

        if pi_stable:
            break

        pi = new_pi

    return pi, v



n = 4
Gamma = [0.8, 0.9, 1]
threshhold = 1e-4

for _gamma in Gamma:
    pi, v = policy_iteration(n=n, Gamma=_gamma, threshhold=threshhold)
    pi_char = policy_int_to_char(pi=pi, n=n)

    print()
    print("Gamma = ", _gamma)
    print()
    print(pi_char)
    print()
    print(v)