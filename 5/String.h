#pragma once
#include <ostream>


class String
{
public:
    String();
    String(const char* cStyleString);
    explicit String(char symbol, unsigned int amount);
    String(const String& string);

    ~String();

    void append(const char* cStyleString);
    void append(const String& string);
    String& operator=(const String& string);
    String& operator+=(const String& string);
    String operator+(const String& string);
    friend std::ostream& operator<<(std::ostream& wave, const String& string);
    void print() const;
    unsigned int size() const;
    void clear();
private:
    char* mData;
    unsigned int mDataSize;
    void initialization(const char* cStyleString);
    char* concatenation(const char* firstString, const char* secondString);
};
