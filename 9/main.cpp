#include "Array.hxx"
#include <iostream>
#include <typeinfo>
#include <tuple>
#include <stdexcept>

using std::cout,
std::endl;

void print_values() {}

template<class Type, class... Args>
void print_values(Type value, Args... args) {
    const Type *pt = &value;
    std::cout << typeid(*pt).name() << ": " << value << '\n';
    print_values(args...);
}

template<size_t F, size_t S, class... Type>
auto to_pair(const std::tuple<Type...> &tuple) -> decltype(std::make_pair(std::get<F>(tuple), std::get<S>(tuple))) {
    return std::make_pair(std::get<F>(tuple), std::get<S>(tuple));
}

int main() {
    print_values(0, 3.5, "Hello");
    cout << endl;
    Array<int> first(3);
    Array<int> second = std::move(first);
    cout << second.size() << ' ' << first.size() << '\n';
    auto t = std::make_tuple(0, 3.5, "Hello world!");
    cout << to_pair<1, 2>(t).first << ' ' << to_pair<1, 2>(t).second;
    return 0;
}
