#include "Player.h"
#include <iostream>

Player::Player(const std::string& playerName) : playerName(playerName) {}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}


void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < benchCards.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemonCard) {
            actionCards.push_back(pokemonCard);
            benchCards.erase(benchCards.begin() + index);
            std::cout << playerName << " activated Pokemon Card: " << pokemonCard->getCardName() << std::endl;
        } else {
            std::cout << "Error: Not a Pokemon Card." << std::endl;
        }
    } else {
        std::cout << "Error: Index out of bounds." << std::endl;
    }
}

void Player::attachEnergyCard(int pokemonIndex, int energyIndex) {
    if (pokemonIndex >= 0 && pokemonIndex < actionCards.size() &&
        energyIndex >= 0 && energyIndex < benchCards.size()) {
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
        if (energyCard) {
            actionCards[pokemonIndex]->attachEnergy(energyCard);
            benchCards.erase(benchCards.begin() + energyIndex);
            std::cout << playerName << " attached Energy Card to Pokemon." << std::endl;
        } else {
            std::cout << "Error: Not an Energy Card." << std::endl;
        }
    } else {
        std::cout << "Error: Index out of bounds." << std::endl;
    }
}

void Player::displayBench() const {
    std::cout << playerName << "'s Bench Cards:" << std::endl;
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}

void Player::displayAction() const {
    std::cout << playerName << "'s Action Cards:" << std::endl;
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
}

void Player::attack(int attackingPokemonIndex, int attackIndex, Player& opponent, int defendingPokemonIndex) {
    if (attackingPokemonIndex >= 0 && attackingPokemonIndex < actionCards.size() &&
        defendingPokemonIndex >= 0 && defendingPokemonIndex < opponent.actionCards.size()) {
        actionCards[attackingPokemonIndex]->attack(attackIndex, opponent.actionCards[defendingPokemonIndex]);
    } else {
        std::cout << "Error: Index out of bounds." << std::endl;
    }
}

void Player::useTrainer(int trainerIndex) {
    if (trainerIndex >= 0 && trainerIndex < benchCards.size()) {
        TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[trainerIndex]);
        if (trainerCard) {
            trainerCard->useEffect();
            benchCards.erase(benchCards.begin() + trainerIndex);
            std::cout << playerName << " used Trainer Card." << std::endl;
        } else {
            std::cout << "Error: Not a Trainer Card." << std::endl;
        }
    } else {
        std::cout << "Error: Index out of bounds." << std::endl;
    }
}
