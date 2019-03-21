#include <iostream>
#include "Array.hxx"
#include "Test.h"

template<class Type, class C>
Type minimum(const Array<Type> &arr, C compare) {
    Type arrMin = arr.size() > 0 ? arr[0] : Type();
    for (size_t i = 0; i < arr.size(); ++i) {
        if (compare(arr[i], arrMin)) {
            arrMin = arr[i];
        }
    }
    return arrMin;
}

template<class Type>
void flatten(const Type &value, std::ostream &output) {
    output << value << ' ';
}

template<class Type>
void flatten(const Array<Type> &arr, std::ostream &output) {
    for (size_t i = 0; i < arr.size(); ++i) {
        flatten(arr[i], output);
    }
}

bool less(int a, int b) {
    return a < b;
}

struct Greater {
    bool operator()(int a, int b) const {
        return b < a;
    }
};

using std::cout,
std::endl;

int main() {
    Array<int> ints(2);
    ints[0] = 10;
    ints[1] = 20;
    flatten(ints, std::cout);
    std::cout << '\n';
    Array<Array<int> > arrOfInts(2, ints);
    flatten(arrOfInts, std::cout);
    std::cout.precision(1);
    std::cout.setf(std::ios::fixed);
    std::cout << '\n';
    Array<double> doubles(10, 0.0);
    flatten(doubles, std::cout);
    std::cout << '\n';
    std::cout << minimum(ints, less) << '\n';
    std::cout << minimum(ints, Greater());
    std::cout << endl;
    Test exA(3);
    Array<Test> testArr(5, exA);


    cout << "testArr: [ ";
    for (size_t i = 0; i < testArr.size(); ++i) {
        cout << testArr[i] << " ";
    }
    cout << "]" << endl;

    testArr = testArr;

    cout << "testArr: [ ";
    for (int i = 0; i < 5; ++i) {
        cout << testArr[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}
