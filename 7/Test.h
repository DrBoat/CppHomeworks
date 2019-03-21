#pragma ones

#include<ostream>
#include <iostream>

class Test {
public:
    Test() = delete;

    Test operator=(const Test &) = delete;

    Test(const int field);

    int getField();

private:
    int mField = 5;
};

std::ostream &operator<<(std::ostream &output, Test &next);
