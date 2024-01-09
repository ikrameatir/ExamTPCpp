#include "EnergyCard.h"
#include <iostream>

EnergyCard::EnergyCard(const std::string& energyType) : Card("Energy"), energyType(energyType) {}

void EnergyCard::displayInfo() const {
    std::cout << "Energy Card: " << cardName << " - Energy Type: " << energyType << std::endl;
}