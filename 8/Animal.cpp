#include "Animal.h"

Animal::Animal(const size_t& id, const size_t& hp, const size_t& intelligence) : Unit(id, hp), mIntelligence(intelligence) {}


size_t Animal::getIntelligence() const
{
    return mIntelligence;
}

void Animal::makeNoize() const
{
    std::cout << "*making an abstract noize*\n";
}

std::string Animal::getTypeName() const
{
    return "Animal";
}
