//
// Created by Elliot Alderson on 09/02/2019.
//

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Human {
public:
    Human();
    Human(const std::string& name, const std::string& location, bool alive, int currentAge, int lifeSpan, int height, long long weight,
          bool gender, long long salary);
    Human(const std::string& name, const std::string& location, int currentAge, int height, long long weight,
          bool gender, long long salary);
    Human(const Human& next);

    Human& operator=(const Human& next);
    Human operator+(const Human& next);
    Human& operator->*(Human& next);
    Human operator-(const Human& next);
    Human operator*(const Human& next);
    Human operator/(const Human& next);
    Human operator%(const Human& next);
    Human operator&(const Human& next);
    Human operator|(const Human& next);
    Human operator^(const Human& next);
    Human operator,(const Human& next);
    Human& operator+=(const Human& next);
    Human& operator-=(const Human& next);
    Human& operator*=(const Human& next);
    Human& operator/=(const Human& next);
    Human& operator%=(const Human& next);
    Human& operator&=(const Human& next);
    Human& operator|=(const Human& next);
    Human& operator^=(const Human& next);
    Human operator()(const Human& first, const Human& next) const;
    Human operator~();
    Human operator+();
    Human operator-();
    Human& operator++();
    Human& operator--();
    Human operator++(int);
    Human operator--(int);
    std::string operator[](const int& newSalary);
    long long operator()(const int& plusSalary);
    long long operator[](const std::string& newJobPlace);
    explicit operator long long() const;
    explicit operator bool() const;
    bool operator!() const;
    bool operator==(const Human& next) const;
    bool operator!=(const Human& next) const;
    bool operator<(const Human& next) const;
    bool operator>(const Human& next) const;
    bool operator<=(const Human& next) const;
    bool operator>=(const Human& next) const;
    bool operator&&(const Human& next) const;
    bool operator||(const Human& next) const;
    friend std::istream& operator>>(std::istream& input, Human& next);
    friend std::ostream& operator<<(std::ostream& output, Human& next);
    friend std::ostream&operator<<=(std::ostream& output , Human& next);
    friend std::istream&operator >>=(std::istream& input , Human& next);


    std::string getName() const;
    std::string getLocation() const;
    std::string getGender() const;
    int getAge() const;
    int getLifeSpan() const;
    int getHeight() const;
    int timeLeft() const;
    long long getWeight() const;
    long long getSalary() const;
    bool isFat() const;
    bool isAlive() const;
    bool isDead() const;
    bool isTall() const;

    void setName(const std::string& name);
    void setLocation(const std::string& location);
    void setAge(int age);
    void setLifeSpan(int lifespan);
    void setHeight(int height);
    void setWeight(long long weight);
    void setGender(bool gender);
    void setSalary(long long salary);
    void grow(int plusHeight);
    void shorten(int minusHeight);
    void plump(long long plusWeight);
    void thinOut(long long minusWeight);
    void raise(long long plusSalary);
    void decrease(long long minusSalary);
    void getNewJob(long long salary);
    void getNewJob(const std::string& location, long long salary);

    const static bool FEMALE = 0;
    const static bool MALE = 1;

private:
    const std::string DEFAULT_NAME = "Ivan";
    const std::string DEFAULT_LOCATION = "Saratov";
    const int DEFAULT_AGE = 0;
    const int DEFAULT_LIFE_SPAN = 70;
    const int DEFAULT_HEIGHT = 53;
    const long long DEFAULT_WEIGHT = 4;
    const int DEFAULT_ADULT_HEIGHT = 175;
    const long long DEFAULT_ADULT_WEIGHT = 75;
    const long long DEFAULT_SALARY = 0;
    const int GENDER_NUMBER = 2;
    const int TALL_LIMIT = 180;

    std::map<int, std::string> mNumToGender;
    std::map<std::string, bool> mGenderToNum;
    std::vector<std::string> mGenders;
    std::string mName;
    std::string mLocation;
    bool mIsAlive;
    int mCurrentAge;
    int mLifeSpan;
    int mHeight;
    long long mWeight;
    bool mGender;
    long long mSalary;
    void mDefaultInit();
    void mDie();
    void mReincarnate();
    void mValidateData(int currentAge, int lifeSpan, int gender, int height, long long weight);
};
