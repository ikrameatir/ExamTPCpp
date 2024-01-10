#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"
#include <string>

class Reptile : public Animal {
private:
    std::string scalePattern;
    
public:
    Reptile() : scalePattern("") {}

    Reptile(const std::string& type, const std::string& name, the std::string& color, 
            const std::string& diet, const std::string& habitat, const std::string& sounds, 
            bool isPet, int age, double weight, double height, const std::string& scalePattern)
        : Animal(type, name, color, diet, habitat, sounds, isPet, age, weight, height), 
          scalePattern(scalePattern) {}

    virtual void printInfo() const override;

    std::string getScalePattern() const { return scalePattern; }
    void setScalePattern(const std::string& newScalePattern) { scalePattern = newScalePattern; }

};

#endif

