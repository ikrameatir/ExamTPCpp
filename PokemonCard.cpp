#include "PokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(const std::string& pokemonName, const std::string& type, const std::string& family,
                         int evolutionLevel, int maxHP, int currentHP,
                         const std::vector<std::tuple<int, int, std::string, int>>& attacks)
    : Card(pokemonName), pokemonType(type), familyName(family),
      evolutionLevel(evolutionLevel), maxHP(maxHP), hp(currentHP), attacks(attacks) {}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card: " << cardName << " - Type: " << pokemonType
              << " - Family: " << familyName << " - Evolution Level: " << evolutionLevel
              << " - Max HP: " << maxHP << " - Current HP: " << hp << std::endl;

    std::cout << "Attacks:" << std::endl;
    for (const auto& attack : attacks) {
        std::cout << "  Cost: " << std::get<0>(attack) << " Current Cost: " << std::get<1>(attack)
                  << " Description: " << std::get<2>(attack) << " Damage: " << std::get<3>(attack) << std::endl;
    }
}