#include "BadFromString.h"

const char *BadFromString::what() const noexcept {
    return mMessage.c_str();
}

BadFromString::BadFromString(const std::string &message) {
    mMessage = message;
}
