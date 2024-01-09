#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(const std::string& name);
    virtual ~Card() = default;

    virtual void displayInfo() const = 0;

protected:
    std::string cardName;
};

class EnergyCard : public Card {
public:
    EnergyCard(const std::string& name);

    void displayInfo() const override;
};

class TrainerCard : public Card {
public:
    TrainerCard(const std::string& name, const std::string& effect);

    void displayInfo() const override;

private:
    std::string effect;
};

class PokemonCard : public Card {
public:
    PokemonCard(const std::string& name, const std::string& type, const std::string& species,
                int level, int health, int energyCost, const std::string& attack1,
                int attack1Damage, int attack2, const std::string& attack2Name, int attack2Damage);

    void displayInfo() const override;

private:
    std::string type;
    std::string species;
    int level;
    int health;
    int energyCost;
    std::string attack1;
    int attack1Damage;
    int attack2;
    std::string attack2Name;
    int attack2Damage;
};

#endif // CARD_H
