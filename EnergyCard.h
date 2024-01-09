#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"

class EnergyCard : public Card {
public:
    EnergyCard(const std::string& energyType);

    void displayInfo() const override;

private:
    std::string energyType;
};

#endif // ENERGYCARD_H
