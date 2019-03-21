#include "Unit.h"

Unit::Unit(const size_t &id, const size_t &hp) : mId(id), mHealth(hp) {}

void Unit::heal(const size_t &number) {
    mHealth += number;
}

void Unit::takeDamage(const size_t &number) {
    if (number >= mHealth) {
        mHealth = 0;
    } else {
        mHealth -= number;
    }
}

std::string Unit::getTypeName() const {
    return "Unit";
}

size_t Unit::getId() const {
    return mId;
}

size_t Unit::getHealth() const {
    return mHealth;
}
