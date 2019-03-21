#pragma once

#include "Bear.h"
#include "Pig.h"
#include "Man.h"

class ManBearPig : public Man, public Bear, public Pig {
public:
    ManBearPig(const size_t &id, const size_t &hp, const size_t &intelligence, const size_t &mass,
               const size_t &strength, const std::string &name,
               const size_t &age, const size_t &gender, const size_t &type);

    void transform(const size_t &type);

    void makeNoize() const override;

    std::string getTypeName() const override;

private:
    const size_t PIG = 0;
    const size_t BEAR = 1;
    const size_t MAN = 2;
    const size_t TYPE_SIZE = 2;
    size_t mCurrentType;
};
