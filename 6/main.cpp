//
// Created by Elliot Alderson on 09/02/2019.
//

#include "Human.h"
#include <iostream>
#include <ctime>

using std::cout, std::endl;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Human firstExemplar("Yury", "Saratov", 19, 168, 75, Human::MALE, 50000);
    cout << firstExemplar << endl;
    Human secondExemplar("Anastasia", "Moscow", 22, 164, 59, Human::FEMALE, 25000);
    cout << secondExemplar << endl;
    Human thirdExemplar = firstExemplar + secondExemplar;
    cout << thirdExemplar << endl;
    return 0;
}
