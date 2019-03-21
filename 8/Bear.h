#pragma once

#include "Animal.h"

class Bear : virtual public Animal
{
public:
    Bear(const size_t& id, const size_t& hp, const size_t& intelligence, const size_t& strength);
    size_t getStrength() const;
    void strengthUp(const size_t& amount);
    std::string getTypeName() const override;
    virtual void makeNoize() const override;
private:
    size_t mPower;
};
