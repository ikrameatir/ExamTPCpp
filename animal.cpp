#include "Animal.h"
#include <iostream>



Animal::Animal() : type(""), name(""), color(""), diet(""), habitat(""), sounds(""),
                   isPet(false), age(0), weight(0.0), height(0.0) {}

Animal::Animal(const std::string& type, const std::string& name, const std::string& color, 
               const std::string& diet, const std::string& habitat, const std::string& sounds, 
               bool isPet, int age, double weight, double height)
    : type(type), name(name), color(color), diet(diet), habitat(habitat), sounds(sounds),
      isPet(isPet), age(age), weight(weight), height(height) {}

Animal::Animal(const Animal& other)
    : type(other.type), name(other.name), color(other.color), diet(other.diet),
      habitat(other.habitat), sounds(other.sounds), isPet(other.isPet),
      age(other.age), weight(other.weight), height(other.height) {}
      

void Animal::makeSound() const {
    std::cout << sounds << std::endl;
}


void printInfo() const {
        std::cout << "Animal of " << (type.empty() ? "unknown type" : type) << ":\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Color: " << color << "\n";
        std::cout << "Diet: " << diet << "\n";
        std::cout << "Habitat: " << habitat << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << (isPet ? "This animal is a pet\n" : "This animal is not a pet\n");
        std::cout << "Weight: " << weight << "\n";
        std::cout << "Height: " << height << "\n";
}

// Setters
void Animal::setName(const std::string& name) {
    this->name = name;
}

void Animal::setColor(const std::string& color) {
    this->color = color;
}

void Animal::setDiet(const std::string& diet) {
    this->diet = diet;
}

void Animal::setHabitat(const std::string& habitat) {
    this->habitat = habitat;
}

void Animal::setSounds(const std::string& sounds) {
    this->sounds = sounds;
}

void Animal::setIsPet(bool isPet) {
    this->isPet = isPet;
}

void Animal::setAge(int age) {
    this->age = age;
}

void Animal::setWeight(double weight) {
    this->weight = weight;
}

void Animal::setHeight(double height) {
    this->height = height;
}

// Getters
std::string Animal::getName() const {
    return name;
}

std::string Animal::getColor() const {
    return color;
}

std::string Animal::getDiet() const {
    return diet;
}

std::string Animal::getHabitat() const {
    return habitat;
}

std::string Animal::getSounds() const {
    return sounds;
}

bool Animal::getIsPet() const {
    return isPet;
}

int Animal::getAge() const {
    return age;
}

double Animal::getWeight() const {
    return weight;
}

double Animal::getHeight() const {
    return height;
}
