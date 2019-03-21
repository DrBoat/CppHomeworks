#include "Bear.h"

Bear::Bear(const size_t &id, const size_t &hp, const size_t &intelligence, const size_t &strength) :
        Unit(id, hp), Animal(id, hp, intelligence), mPower(strength) {}

size_t Bear::getStrength() const {
    return mPower;
}

void Bear::strengthUp(const size_t &amount) {
    mPower += amount;
}

std::string Bear::getTypeName() const {
    return "Bear";
}

void Bear::makeNoize() const {
    std::cout << "AAAAARRRRRRRRRRR\n";
}
