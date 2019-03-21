#include "Man.h"

Man::Man(const size_t &id, const size_t &hp, const std::string &name, const size_t &age, const size_t &gender) :
        Unit(id, hp), mName(name), mAge(age), mGender(gender) {
    if (gender > 1) {
        mGender = gender % 2;
    }
}

size_t Man::getAge() const {
    return mAge;
}

size_t Man::getGender() const {
    return mGender;
}

std::string Man::getName() const {
    return mName;
}

std::string Man::getTypeName() const {
    return "Man";
}
