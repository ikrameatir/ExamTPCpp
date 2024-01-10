#include "mammal.h"
#include <iostream>

void Mammal::printInfo() const {
        Animal::printInfo(); 
        std::cout << "Fur Color: " << furColor << "\n";
    }
