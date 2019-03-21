#pragma once

#include "Unit.h"

class Animal : virtual public Unit
{
public:
    Animal(const size_t& id, const size_t& hp, const size_t& intelligence);
    size_t getIntelligence() const;
    virtual void makeNoize() const;
    std::string getTypeName() const override;
protected:
    size_t mIntelligence;
};
