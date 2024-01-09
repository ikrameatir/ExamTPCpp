#include "card.h"
#include <iostream>

Card::Card(const std::string& name) : cardName(name) {}

EnergyCard::EnergyCard(const std::string& name) : Card(name) {}

void EnergyCard::displayInfo() const {
    std::cout << "Energy Card: " << cardName << std::endl;
}

TrainerCard::TrainerCard(const std::string& name, const std::string& effect) : Card(name), effect(effect) {}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card: " << cardName << " - Effect: " << effect << std::endl;
}

PokemonCard::PokemonCard(const std::string& name, const std::string& type, const std::string& species,
                         int level, int health, int energyCost, const std::string& attack1,
                         int attack1Damage, int attack2, const std::string& attack2Name, int attack2Damage)
    : Card(name), type(type), species(species), level(level), health(health),
      energyCost(energyCost), attack1(attack1), attack1Damage(attack1Damage),
      attack2(attack2), attack2Name(attack2Name), attack2Damage(attack2Damage) {}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card: " << cardName << " - Type: " << type << " - Species: "
              << species << " - Level: " << level << " - Health: " << health << std::endl;
}
