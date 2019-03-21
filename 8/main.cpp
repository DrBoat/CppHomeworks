#include "Pig.h"
#include "Bear.h"
#include "Unit.h"
#include "ManBearPig.h"

#include <iostream>

using std::cout;
using std::endl;

template
class std::basic_string<char>;

typedef int (*firstFunction)(double);

typedef int *(*secondFunction)(char const *);

typedef secondFunction (*ComplexFunction)(int, firstFunction);

template<class F, class S>
bool compare(const F &first, const F &second, S (F::*method)() const) {
    return (first.*method)() < (second.*method)();
}

template<class T>
bool isSameObject(T *first, T *second) {
    return dynamic_cast<void *>(first) == dynamic_cast<void *>(second);
}

int main() {
    std::string s1("Elf");
    std::string s2("Archer");

    bool r1 = compare(s1, s2, &std::string::size); //true
    bool r2 = compare(s1, s1, &std::string::size); //false

    cout << "r1 is " << (r1 ? "true" : "false") << endl;
    cout << "r2 is " << (r2 ? "true" : "false") << endl;

    Pig firstExemplar(12, 100, 4, 7);
    Bear thirdExemplar(12, 100, 4, 7);
    firstExemplar.makeNoize();
    Animal *secondExemplar = &thirdExemplar;
    Unit *fourtExemplar = &thirdExemplar;
    secondExemplar->makeNoize();
    std::cout << fourtExemplar->getTypeName() << '\n';
    ManBearPig firstExmpOfMbp(1, 1, 1, 1, 1, "1", 1, 0, 0);
    ManBearPig secondExmpOfMbp(1, 1, 1, 1, 1, "1", 1, 0, 0);
    Pig *firstPointer = &firstExmpOfMbp;
    Pig *secondPointer = &firstExmpOfMbp;
    firstPointer->makeNoize();
    std::cout << ((isSameObject(firstPointer, secondPointer)) ? "true" : "false") << endl;
    return 0;
}