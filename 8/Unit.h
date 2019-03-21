#pragma once

#include <string>
#include <iostream>

class Unit {
public:
    Unit(const size_t &id, const size_t &hp);

    void heal(const size_t &number);

    void takeDamage(const size_t &number);

    virtual std::string getTypeName() const;

    size_t getId() const;

    size_t getHealth() const;

protected:
    size_t mId;
    size_t mHealth;
};
