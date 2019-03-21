#pragma once

#include "Array.h"
#include <cstdio>
#include <algorithm>


template<class Type>
Array<Type>::Array(size_t arrSize, const Type &value) : mSize(arrSize) {
    allocateStorage(mSize);
    for (size_t i = 0; i < mSize; ++i) {
        new(mData + i) Type(value);
    }
}

template<class Type>
Array<Type>::Array(const Array &next) : mSize(next.size()) {
    allocateStorage(mSize);
    for (size_t i = 0; i < mSize; ++i) {
        new(mData + i) Type(next.mData[i]);
    }
}

template<class Type>
Array<Type>::~Array() {
    clear();
}

template<typename Type>
void Array<Type>::clear() {
    for (size_t i = 0; i < mSize; ++i) {
        (mData + i)->~Type();
    }
    delete[] (char *) mData;
    mSize = 0;
    mData = nullptr;
}

template<class Type>
Array<Type> &Array<Type>::operator=(const Array &other) {
    if (this == &other) {
        return *this;
    }
    clear();
    mSize = other.size();
    allocateStorage(other.size());
    for (size_t i = 0; i < other.size(); ++i) {
        new(mData + i) Type(other[i]);
    }
    return *this;
}

template<class Type>
size_t Array<Type>::size() const {
    return mSize;
}

template<class Type>
Type &Array<Type>::operator[](size_t index) {
    return (index >= mSize) ? mData[mSize - 1] : mData[index];
}

template<class Type>
const Type &Array<Type>::operator[](size_t index) const {
    return (index >= mSize) ? mData[mSize - 1] : mData[index];
}

template<typename Type>
void Array<Type>::allocateStorage(size_t elements_cnt) {
    mData = (Type *) new char[sizeof(Type) * elements_cnt];
}
