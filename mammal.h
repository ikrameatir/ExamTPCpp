#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"
#include <string>

class Mammal : public Animal {
private:
    std::string furColor;
public:
    Mammal() : furColor("") {}

    Mammal(const std::string& type, const std::string& name, const std::string& color, const std::string& diet, 
           const std::string& habitat, const std::string& sounds, bool isPet, int age, double weight, 
           double height, const std::string& furColor)
        : Animal(type, name, color, diet, habitat, sounds, isPet, age, weight, height), furColor(furColor) {}

    virtual void printInfo() const override;

    std::string getFurColor() const { return furColor; }
    void setFurColor(const std::string& newFurColor) { furColor = newFurColor; }

};

#endif 
