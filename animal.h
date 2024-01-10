#ifndef ANIMAL_H
#define ANIMAL_H


#include <string>
#include <iostream>

class Animal {
private:
    std::string type;
    std::string name;
    std::string color;
    std::string diet;
    std::string habitat;
    std::string sounds;
    bool isPet;
    int age;
    double weight;
    double height;

public:
    // Constructeur par défaut
    Animal() : type(""), name(""), color(""), diet(""), habitat(""), sounds(""),
               isPet(false), age(0), weight(0.0), height(0.0) {}

    // Constructeur paramétré
    Animal(const std::string& type, const std::string& name, const std::string& color, 
           const std::string& diet, const std::string& habitat, const std::string& sounds, 
           bool isPet, int age, double weight, double height)
        : type(type), name(name), color(color), diet(diet), habitat(habitat), sounds(sounds),
          isPet(isPet), age(age), weight(weight), height(height) {}

    // Constructeur de copie
    Animal(const Animal& other)
        : type(other.type), name(other.name), color(other.color), diet(other.diet),
          habitat(other.habitat), sounds(other.sounds), isPet(other.isPet),
          age(other.age), weight(other.weight), height(other.height) {}

    // Setters
    void setType(const std::string& type) { this->type = type; }
    void setName(const std::string& name) { this->name = name; }
    void setColor(const std::string& color) { this->color = color; }
    void setDiet(const std::string& diet) { this->diet = diet; }
    void setHabitat(const std::string& habitat) { this->habitat = habitat; }
    void setSounds(const std::string& sounds) { this->sounds = sounds; }
    void setIsPet(bool isPet) { this->isPet = isPet; }
    void setAge(int age) { this->age = age; }
    void setWeight(double weight) { this->weight = weight; }
    void setHeight(double height) { this->height = height; }

    // Getters
    std::string getType() const { return type; }
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
    std::string getDiet() const { return diet; }
    std::string getHabitat() const { return habitat; }
    std::string getSounds() const { return sounds; }
    bool getIsPet() const { return isPet; }
    int getAge() const { return age; }
    double getWeight() const { return weight; }
    double getHeight() const { return height; }
    
    void makeSound() const;
    virtual void printInfo() const;
};
#endif

