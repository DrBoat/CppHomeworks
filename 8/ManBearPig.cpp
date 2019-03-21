#include "ManBearPig.h"

ManBearPig::ManBearPig(const size_t &id, const size_t &hp, const size_t &intelligence, const size_t &mass,
                       const size_t &strength,
                       const std::string &name, const size_t &age, const size_t &gender, const size_t &type) :
                       Unit(id, hp), Animal(id, hp, intelligence), Pig(id, hp, intelligence, mass),
                       Bear(id, hp, intelligence, strength), Man(id, hp, name, age, gender), mCurrentType(type) {}

void ManBearPig::transform(const size_t &type) {
    if (type > TYPE_SIZE) {
        mCurrentType = type % 3;
    }
}

void ManBearPig::makeNoize() const {
    if (mCurrentType == PIG) {
        std::cout << "HRHRHRHRHRRHRHRHRHRHRHHR\n";
    }
    if (mCurrentType == BEAR) {
        std::cout << "AAAAARRRRRRRRRRR\n";
    }
    if (mCurrentType == MAN) {
        std::cout << "Hello!\n";
    }
}

std::string ManBearPig::getTypeName() const {
    if (mCurrentType == PIG) {
        return "Pig";
    }
    else if (mCurrentType == BEAR) {
        return "Bear";
    }
    else if (mCurrentType == MAN) {
        return "Man";
    } else {
        return "ManBearPig";
    }
}
