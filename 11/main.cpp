#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <typeinfo>

#include "ConvertString.hxx"

using std::cout, std::endl,
std::cerr;

int main() {
    std::vector<std::string> strings = {"123", "123.2", "abc bs", "123123123123123123", "a", "", " ", " 1337", "125 ",
                                        "1"};
    for (const auto &input : strings) {
        try {
            auto result = fromString<int>(input);
            cout << result << endl;
        } catch (BadFromString &badFromString) {
            cerr << badFromString.what() << endl;
        }
        try {
            auto result = fromString<double>(input);
            cout << result << std::endl;
        } catch (BadFromString &badFromString) {
            cerr << badFromString.what() << endl;
        }
        try {
            auto result = fromString<std::string>(input);
            cout << result << std::endl;
        } catch (BadFromString &badFromString) {
            cerr << badFromString.what() << endl;
        }
        try {
            auto result = fromString<char>(input);
            cout << result << endl;
        } catch (BadFromString &badFromString) {
            cerr << badFromString.what() << endl;
        }
        try {
            auto result = fromString<long>(input);
            cout << result << endl;
        } catch (BadFromString &badFromString) {
            cerr << badFromString.what() << endl;
        }
        try {
            auto result = fromString<short>(input);
            cout << result << endl;
        } catch (BadFromString &badFromString) {
            cerr << badFromString.what() << endl;
        }
        try {
            auto result = fromString<bool>(input);
            cout << (result ? "true" : "false") << endl;
        } catch (BadFromString &badFromString) {
            cerr << badFromString.what() << endl;
        }
        cout << "____________________________" << endl << endl;
    }
    std::string sss = "123";
    std::string sss1 = fromString<std::string>(sss);
    cout << sss1 << endl;
    return 0;
}
