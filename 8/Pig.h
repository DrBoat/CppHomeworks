#pragma once

#include "Animal.h"

class Pig : virtual public Animal {
public:
    Pig(const size_t &id, const size_t &hp, const size_t &intelligence, const size_t &mass);

    size_t getMass() const;

    void massUp(const size_t &number);

    std::string getTypeName() const override;

    virtual void makeNoize() const override;

private:
    size_t mMass;
};
