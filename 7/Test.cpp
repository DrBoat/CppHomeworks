#include "Test.h"

Test::Test(const int field) : mField(field) {};

int Test::getField() {
    return mField;
}

std::ostream &operator<<(std::ostream &output, Test &next) {
    output << next.getField();
    return output;
}

