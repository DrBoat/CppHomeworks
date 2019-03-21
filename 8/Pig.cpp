#include "Pig.h"

Pig::Pig(const size_t &id, const size_t &hp, const size_t &intelligence, const size_t &mass) :
         Unit(id, hp),  Animal(id, hp, intelligence), mMass(mass) {}

size_t Pig::getMass() const {
    return mMass;
}

void Pig::massUp(const size_t &number) {
    mMass += number;
}

std::string Pig::getTypeName() const {
    return "Pig";
}

void Pig::makeNoize() const {
    std::cout << "HRHRHRHRHRRHRHRHRHRHRHHR\n";
}
