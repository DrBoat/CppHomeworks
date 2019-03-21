#pragma once

#include <string>
#include <exception>

class BadFromString : std::exception {
public:
    explicit BadFromString(const std::string &message);

    const char *what() const noexcept override;

private:
    std::string mMessage;
};