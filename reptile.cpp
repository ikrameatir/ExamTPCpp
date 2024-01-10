#include "Reptile.h"
#include <iostream>

void Reptile::printInfo() const {
    Animal::printInfo();
    std::cout << "Scale Pattern: " << scalePattern << "\n";
}

