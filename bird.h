#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <string>

class Bird : public Animal {
private:
    double wingspan;
public:
    Bird() : wingspan(0.0) {}

    Bird(const std::string& type, const std::string& name, const std::string& color, const std::string& diet, 
         const std::string& habitat, const std::string& sounds, bool isPet, int age, double weight, 
         double height, double wingspan)
        : Animal(type, name, color, diet, habitat, sounds, isPet, age, weight, height), wingspan(wingspan) {}

    Bird(const Bird& other)
        : Animal(other), wingspan(other.wingspan) {}

    virtual void printInfo() const override;

    double getWingspan() const { return wingspan; }
    void setWingspan(double newWingspan) { wingspan = newWingspan; }

};

#endif
