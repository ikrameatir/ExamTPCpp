#include "Zoo.h"
#include "KNNDouble.h"
#include "KNNString.h"


#include <iostream>

Zoo::Zoo() : name("Default Zoo") {}

Zoo::Zoo(const std::string& name) : name(name) {}

Zoo::Zoo(const Zoo& other) : name(other.name) {
    for (const auto& animal : other.animals) {
        animals.push_back(new Animal(*animal));
    }
}

Zoo::~Zoo() {
    for (auto& animal : animals) {
        delete animal;
    }
}

void Zoo::setName(const std::string& name) {
    this->name = name;
}

std::string Zoo::getName() const {
    return name;
}

void Zoo::listAnimals() const {
    for (const auto& animal : animals) {
        animal->printInfo();
    }
}

bool Zoo::addAnimal(Animal* newAnimal) {
    if (animals.size() >= MAX_CAPACITY) {
        return false;
    }
    auto it = std::lower_bound(animals.begin(), animals.end(), newAnimal,
        [](const Animal* a, const Animal* b) {
            return a->getName() < b->getName();
        });
    animals.insert(it, newAnimal);
    return true;
}

int Zoo::searchAnimalByName(const std::string& name) const {
    for (size_t i = 0; i < animals.size(); ++i) {
        if (animals[i]->getName() == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void Zoo::removeAnimalByName(const std::string& name) {
    auto it = std::find_if(animals.begin(), animals.end(),
        [&name](const Animal* animal) { return animal->getName() == name; });

    if (it != animals.end()) {
        delete *it;
        animals.erase(it);
    } else {
        std::cout << "L'animal avec le nom' " << name << " ne se trouve pas dans le Zoo.\n";
    }
}

double Zoo::averageAgeForType(const std::string& type) const {
    double totalAge = 0.0;
    int count = 0;

    for (const auto& animal : animals) {
        if (animal->getType() == type) {
            totalAge += animal->getAge();
            ++count;
        }
    }

    return count > 0 ? totalAge / count : 0.0;
}

std::string Zoo::predictTypeWithKNN(const Animal& newAnimal, int k, const std::string& dataType) {
    if (dataType == "numerical") {
        std::vector<std::pair<double, double>> trainData;
        for (const auto& animal : animals) {
            trainData.emplace_back(animal->getWeight(), animal->getHeight());
        }
        std::pair<double, double> target = std::make_pair(newAnimal.getWeight(), newAnimal.getHeight());
        
        KNNDouble knn(k);
        auto neighbors = knn.findNearestNeighbours(trainData, target);
    } else if (dataType == "categorical") {
        std::vector<std::vector<std::string>> trainData;
        for (const auto& animal : animals) {
            trainData.push_back({animal->getColor(), animal->getDiet(), animal->getHabitat(), animal->getSounds()});
        }
        std::vector<std::string> target = {newAnimal.getColor(), newAnimal.getDiet(), newAnimal.getHabitat(), newAnimal.getSounds()};
        
        KNNString knn(k);
        auto neighbors = knn.findNearestNeighbours(trainData, target);
    }
    return "inconnu";
}


