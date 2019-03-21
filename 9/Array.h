#pragma once

#include <cctype>

template<class Type>
class Array {
public:
    /*
     * you need to pass object explicitly if it isn't default constructable
     */
    explicit Array(size_t arrSize = 0, const Type &value = Type());

    Array(Array const &arr);

    Array(Array &&arr);

    ~Array();

    Array &operator=(const Array &next);

    Array operator=(Array &&next);

    size_t size() const;

    Type &operator[](size_t index);

    const Type &operator[](size_t index) const;

    void clear();

private:
    void swap(Array &next);

    void allocateStorage(size_t elements_cnt);

    Type *mData;
    size_t mSize;
};