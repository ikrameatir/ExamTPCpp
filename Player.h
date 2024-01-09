#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"

class Player {
public:
    Player(const std::string& playerName);

    void addCardToBench(Card* card);
    void activatePokemonCard(int index);
    void attachEnergyCard(int pokemonIndex, int energyIndex);
    void displayBench() const;
    void displayAction() const;
    void attack(int attackingPokemonIndex, int attackIndex, Player& opponent, int defendingPokemonIndex);
    void useTrainer(int trainerIndex);

private:
    std::string playerName;
    std::vector<Card*> benchCards;
    std::vector<PokemonCard*> actionCards;
};

#endif // PLAYER_H