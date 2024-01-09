#include "TrainerCard.h"
#include <iostream>

TrainerCard::TrainerCard(const std::string& trainerName, const std::string& effect)
    : Card(trainerName), trainerEffect(effect) {}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card: " << cardName << " - Effect: " << trainerEffect << std::endl;
}

void TrainerCard::useEffect() {
    // Implémenter l'effet spécifique
    if (trainerEffect == "heal all your action pokemon") {
        std::cout << "Effect used: Heal all your action Pokemon" << std::endl;
        // Mettez en œuvre la logique pour remettre les HP au maximum pour tous les Pokemon en action.
        // Ceci pourrait impliquer de parcourir la liste des Pokemon en action et de mettre à jour leurs HP.
    } else {
        std::cout << "Unknown effect: " << trainerEffect << std::endl;
    }
}