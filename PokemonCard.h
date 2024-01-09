#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <vector>
#include <tuple>

class PokemonCard : public Card {
public:
    PokemonCard(const std::string& pokemonName, const std::string& type, const std::string& family,
                int evolutionLevel, int maxHP, int currentHP,
                const std::vector<std::tuple<int, int, std::string, int>>& attacks);

    void displayInfo() const override;

private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    std::vector<std::tuple<int, int, std::string, int>> attacks;
};

#endif // POKEMONCARD_H