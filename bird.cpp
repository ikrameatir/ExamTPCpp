#include "Bird.h"
#include <iostream>

void Bird::printInfo() const {
    Animal::printInfo();
    std::cout << "Wingspan: " << wingspan << " meters\n";
}
