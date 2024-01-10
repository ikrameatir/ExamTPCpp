#ifndef ZOO_H
#define ZOO_H

#include "Animal.h"
#include <string>
#include <vector>
#include <algorithm>

class Zoo {
private:
    std::string name;
    static const int MAX_CAPACITY = 1000;
    std::vector<Animal*> animals;

public:
    Zoo();
    explicit Zoo(const std::string& name);
    Zoo(const Zoo& other);
    ~Zoo();

    void setName(const std::string& name);
    std::string getName() const;

    void listAnimals() const;
    bool addAnimal(Animal* newAnimal);
    int searchAnimalByName(const std::string& name) const;
    void removeAnimalByName(const std::string& name);
    double averageAgeForType(const std::string& type) const;
    std::string predictTypeWithKNN(const Animal& newAnimal, int k, const std::string& dataType);

};

#endif

