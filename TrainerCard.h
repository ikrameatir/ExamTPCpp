#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"

class TrainerCard : public Card {
public:
    TrainerCard(const std::string& trainerName, const std::string& effect);

    void displayInfo() const override;
    void useEffect();

private:
    std::string trainerEffect;
};

#endif // TRAINERCARD_H
