#pragma once

#include "BadFromString.h"
#include "ConvertString.h"
#include <string>
#include <sstream>
#include <typeinfo>
#include <map>


template<class T>
T fromString(const std::string &input) {
    std::map<std::string, std::string> typeName;

    typeName["i"] = "integer";
    typeName["c"] = "char";
    typeName["d"] = "double";
    typeName["s"] = "short";
    typeName["l"] = "long";
    typeName["b"] = "bool";
    typeName["NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE"] = "string";

    T result;
    std::istringstream reader(input);
    reader >> std::noskipws >> result;
    bool failed = reader.fail();
    reader.get();
    if (failed || !reader.eof()) {
        std::string message =
                "Failed to read a variable of type " + typeName[typeid(T).name()] + " for an input string '" + input +
                "'";
        throw BadFromString(message);
    }
    return result;
}
