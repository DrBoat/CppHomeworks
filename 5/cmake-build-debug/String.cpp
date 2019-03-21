#include <iostream>
#include <cstring>
#include "../String.h"

String::String()
{
    initialization(nullptr);
}

String::String(const char* cStyleString)
{
    initialization(cStyleString);
}

String::String(const char symbol, const unsigned int amount)
{
    char* newString = new char[amount + 1];
    for (int i = 0; i < amount; ++i)
    {
        newString[i] = symbol;
    }
    newString[amount] = '\0';
    initialization(newString);
    delete[] newString;
}

String::String(const String& string)
{
    initialization(string.mData);
}

String::~String()
{
    delete[] mData;
}

void String::append(const char* cStyleString)
{
    if (cStyleString != nullptr)
    {
        char* result = concatenation(mData, cStyleString);
        delete[] mData;
        initialization(result);
        delete[] result;
    }
}

void String::append(const String& string)
{
    this->append(string.mData);
}

String& String::operator=(const String& string)
{
    if (this != &string)
    {
        delete[] mData;
        initialization(string.mData);
    }
    return *this;
}

String& String::operator+=(const String& string)
{
    this->append(string.mData);
    return *this;
}

String String::operator+(const String& string)
{
    String localString(*this);
    localString.append(string);
    return localString;
}

void String::print() const
{
    std::cout << *this;
}

unsigned int String::size() const
{
    return mDataSize;
}

void String::clear()
{
    delete[] mData;
    mData = nullptr;
    mDataSize = 0;
}

void String::initialization(const char* cStyleString)
{
    if (cStyleString)
    {
        mDataSize = (unsigned int)strlen(cStyleString);
        mData = new char[mDataSize + 1];
        strcpy(mData, cStyleString);
        mData[mDataSize] = '\0';
    }
    else
    {
        mData = nullptr;
        mDataSize = 0;
    }
}

char* String::concatenation(const char* firstString, const char* secondString)
{
    unsigned int firstSize = (firstString) ? (unsigned int)strlen(firstString) : 0;
    unsigned int secondSize = (secondString) ? (unsigned int)strlen(secondString) : 0;

    char* result = new char[firstSize + secondSize + 1];

    for (int i = 0; i < firstSize; ++i)
    {
        result[i] = firstString[i];
    }

    for (int i = 0; i < secondSize; ++i)
    {
        result[i + firstSize] = secondString[i];
    }

    result[firstSize + secondSize] = '\0';
    return result;
}

std::ostream& operator<<(std::ostream& wave, const String& string)
{
    if (string.mData)
    {
        wave << string.mData;
    }
    return wave;
}


