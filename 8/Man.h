#pragma once

#include "Unit.h"

class Man : virtual public Unit {
public:
    Man(const size_t &id, const size_t &hp, const std::string &name, const size_t &age, const size_t &gender);

    size_t getAge() const;

    size_t getGender() const;

    std::string getName() const;

    std::string getTypeName() const override;

private:
    const size_t MALE = 1;
    const size_t FEMALE = 0;
    std::string mName;
    size_t mAge;
    size_t mGender;
};
