//
// Created by Elliot Alderson on 09/02/2019.
//

#include "Human.h"

Human::Human() : mCurrentAge(DEFAULT_AGE), mIsAlive(true), mName(DEFAULT_NAME), mLocation(DEFAULT_LOCATION), mLifeSpan(DEFAULT_LIFE_SPAN),
                 mHeight(DEFAULT_HEIGHT), mWeight(DEFAULT_WEIGHT), mGender(static_cast<bool>(rand() % GENDER_NUMBER)), mSalary(DEFAULT_SALARY) {
    mDefaultInit();
}

Human::Human(const std::string& name, const std::string& location, bool alive, int currentAge, int lifeSpan, int height, long long weight, bool gender,
             long long salary) : mName(name), mLocation(location), mIsAlive(alive), mCurrentAge(currentAge), mLifeSpan(lifeSpan), mHeight(height),
                                 mWeight(weight), mGender(gender), mSalary(salary)
{
    mDefaultInit();
    mValidateData(currentAge, lifeSpan, gender, height, weight);
}


Human::Human(const std::string& name, const std::string& location, int currentAge, int height, long long weight, bool gender, long long salary
) : mName(name), mLocation(location), mIsAlive(true), mCurrentAge(currentAge), mLifeSpan(DEFAULT_LIFE_SPAN), mHeight(height),
    mWeight(weight), mGender(gender), mSalary(salary)
{
    mDefaultInit();
    mValidateData(currentAge, currentAge, gender, height, weight);
}

Human::Human(const Human& next) : mName(next.getName()), mLocation(next.getLocation()), mIsAlive(next.isAlive()), mCurrentAge(next.getAge()),
                                  mLifeSpan(next.mLifeSpan), mHeight(next.getHeight()), mWeight(next.getWeight()), mGender(mGenderToNum[next.getGender()]), mSalary(next.getSalary())
{
    mDefaultInit();
}

Human& Human::operator=(const Human& next)
{
    mName = next.getName();
    mLocation = next.getLocation();
    mIsAlive = next.isAlive();
    mCurrentAge = next.getAge();
    mLifeSpan = next.mLifeSpan;
    mHeight = next.getHeight();
    mWeight = next.getWeight();
    mGender = static_cast<bool>(mGenderToNum[next.getGender()]);
    mSalary = next.getSalary();
    return *this;
}

Human Human::operator+(const Human& next)
{
    std::string longerName = next.getName().size() > mName.size() ? next.getName() : mName;
    std::string newLocation = next.getLocation() + ", " + mLocation;
    bool alive = mIsAlive || next.isAlive();
    int age = mCurrentAge + next.getAge();
    int lifeSpan = mLifeSpan + next.mLifeSpan;
    int height = std::max(mHeight, next.getHeight());
    long long weight = std::max(mWeight, next.getWeight());
    bool gender = mGender | mGenderToNum[next.getGender()];
    long long salary = mSalary + next.getSalary();
    return Human(longerName, newLocation, alive, age, lifeSpan, height, weight, gender, salary);
}

Human& Human::operator->*(Human& next)
{
    if (timeLeft() >= next.timeLeft())
    {
        return *this;
    }
    else
    {
        return next;
    }
}

Human Human::operator-(const Human& next)
{
    std::string shorterName = next.getName().size() < mName.size() ? next.getName() : mName;
    std::string newLocation = DEFAULT_LOCATION;
    bool alive = mIsAlive & next.isAlive();
    int age = mCurrentAge - next.getAge();
    int lifeSpan = abs(mLifeSpan - next.mLifeSpan);
    int height = std::min(mHeight, next.getHeight());
    long long weight = std::min(mWeight, next.getWeight());
    bool gender = mGender & mGenderToNum[next.getGender()];
    long long salary = mSalary - next.getSalary();
    return Human(shorterName, newLocation, alive, age, lifeSpan, height, weight, gender, salary);
}

Human Human::operator*(const Human& next)
{
    std::string newName = mName + next.getName();
    std::string newLocation = mLocation + next.getLocation();
    bool alive = mIsAlive || next.isAlive();
    int age = mCurrentAge * next.getAge();
    int lifeSpan = mLifeSpan * next.getLifeSpan();
    int height = mHeight + next.getHeight();
    long long weight = mWeight + next.getWeight();
    bool gender = mGender | mGenderToNum[next.getGender()];
    long long salary = mSalary * next.getSalary();
    return Human(newName, newLocation, alive, age, lifeSpan, height, weight, gender, salary);
}

Human Human::operator/(const Human& next)
{
    std::string newName = DEFAULT_NAME;
    std::string newLocation = DEFAULT_LOCATION;
    bool alive = mIsAlive && next.isAlive();
    int age = mCurrentAge / next.getAge();
    int lifeSpan = mLifeSpan / next.getLifeSpan();
    int height = std::min(mHeight, next.getHeight());
    long long weight = std::min(mWeight, next.getWeight());
    bool gender = mGender & mGenderToNum[next.getGender()];
    long long salary = mSalary / next.getSalary();
    return Human(newName, newLocation, alive, age, lifeSpan, height, weight, gender, salary);
}

Human Human::operator%(const Human& next)
{
    std::string newName = DEFAULT_NAME;
    std::string newLocation = DEFAULT_LOCATION;
    bool alive = mIsAlive && next.isAlive();
    int age = mCurrentAge % next.getAge();
    int lifeSpan = mLifeSpan % next.getLifeSpan();
    int height = mHeight % next.getHeight();
    long long weight = mWeight % next.getWeight();
    bool gender = mGender & mGenderToNum[next.getGender()];
    long long salary = mSalary % next.getSalary();
    return Human(newName, newLocation, alive, age, lifeSpan, height, weight, gender, salary);
}

Human Human::operator&(const Human& next)
{
    bool alive = mIsAlive & next.isAlive();
    bool gender = mGender & mGenderToNum[next.getGender()];
    long long salary = std::min(mSalary, next.getSalary());
    int lifeSpan = std::min(mLifeSpan, next.getLifeSpan());
    int height = std::min(mHeight, next.getHeight());
    long long weight = std::min(mWeight, next.getWeight());
    return Human(mName, mLocation, alive, mCurrentAge, lifeSpan, height, weight, gender, salary);
}

Human Human::operator|(const Human& next)
{
    bool alive = mIsAlive | next.isAlive();
    bool gender = mGender | mGenderToNum[next.getGender()];
    long long salary = mSalary + next.getSalary();
    int lifeSpan = std::max(mLifeSpan, next.getLifeSpan());
    int height = mHeight + next.getHeight();
    long long weight = mWeight + next.getWeight();
    return Human(mName, mLocation, alive, mCurrentAge, lifeSpan, height, weight, gender, salary);
}

Human Human::operator^(const Human& next)
{
    bool alive = mIsAlive ^ next.isAlive();
    bool gender = mGender ^ mGenderToNum[next.getGender()];
    return Human(mName, mLocation, alive, mCurrentAge, mLifeSpan, mHeight, mWeight, gender, mSalary);
}

Human& Human::operator+=(const Human& next)
{
    *this = *this + next;
    return *this;
}

Human& Human::operator-=(const Human& next)
{
    *this = *this - next;
    return *this;
}

Human& Human::operator*=(const Human& next)
{
    *this = *this * next;
    return *this;
}

Human& Human::operator/=(const Human& next)
{
    *this = *this / next;
    return *this;
}

Human& Human::operator%=(const Human& next)
{
    *this = *this % next;
    return *this;
}

Human& Human::operator&=(const Human& next)
{
    *this = *this & next;
    return *this;
}

Human& Human::operator|=(const Human& next)
{
    *this = *this | next;
    return *this;
}

Human& Human::operator^=(const Human& next)
{
    *this = *this ^ next;
    return *this;
}

Human Human::operator~()
{
    bool alive = !mIsAlive;
    bool gender = ~mGender;
    return Human(mName, mLocation, alive, mCurrentAge, mLifeSpan, mHeight, mWeight, gender, mSalary);
}

Human Human::operator+()
{
    Human human(*this);
    human.mReincarnate();
    return human;
}

Human Human::operator-()
{
    Human human(*this);
    human.mDie();
    return human;
}

Human Human::operator,(const Human& next)
{
    return *this + next;
}

Human& Human::operator++()
{
    this->mCurrentAge++;
    this->mValidateData(mCurrentAge, mLifeSpan, mGender, mHeight, mWeight);
    return *this;
}

Human& Human::operator--()
{
    this->mCurrentAge--;
    this->mValidateData(mCurrentAge, mLifeSpan, mGender, mHeight, mWeight);
    return *this;
}

Human Human::operator++(int)
{
    Human human = *this;
    ++human;
    return human;
}

Human Human::operator--(int)
{
    Human human = *this;
    --human;
    return human;
}

long long Human::operator[](const std::string& newJobPlace)
{
    long long newSalary = rand() % 1000000;
    setSalary(newSalary);
    return getSalary();
}

std::string Human::operator[](const int& newSalary)
{
    setLocation("Moscow");
    return getLocation();
}

long long Human::operator()(const int& plusSalary)
{
    raise(plusSalary);
    return getSalary();
}

Human::operator long long() const
{
    return mSalary + mWeight + mHeight;
}

Human::operator bool() const
{
    return int() > 0;
}

bool Human::operator!() const
{
    return !mIsAlive;
}

bool Human::operator==(const Human& next) const
{
    return false;
}

bool Human::operator!=(const Human& next) const
{
    return true;
}

bool Human::operator<(const Human& next) const
{
    return mCurrentAge < next.mCurrentAge;
}

bool Human::operator>(const Human& next) const
{
    return mCurrentAge > next.mCurrentAge;
}

Human Human::operator()(const Human& first, const Human& next) const
{
    if (first > next)
    {
        return first;
    }
    else
    {
        return next;
    }
}

bool Human::operator<=(const Human& next) const
{
    return mCurrentAge <= next.mCurrentAge;
}

bool Human::operator>=(const Human & next) const
{
    return mCurrentAge >= next.mCurrentAge;
}

bool Human::operator&&(const Human & next) const
{
    return next.isAlive() && mIsAlive;
}

bool Human::operator||(const Human & next) const
{
    return next.isAlive() || mIsAlive;
}

std::string Human::getName() const
{
    return mName;
}

std::string Human::getLocation() const
{
    return mLocation;
}

std::string Human::getGender() const
{
    return mNumToGender.at(mGender);
}

int Human::getAge() const
{
    return mCurrentAge;
}

int Human::getHeight() const
{
    return mHeight;
}

int Human::getLifeSpan() const
{
    return mLifeSpan;
}

int Human::timeLeft() const
{
    return mLifeSpan - mCurrentAge;
}

long long Human::getWeight() const
{
    return mWeight;
}

long long Human::getSalary() const
{
    return mSalary;
}

bool Human::isFat() const {
    return mWeight > 100;
}

bool Human::isDead() const {
    return !mIsAlive;;
}

bool Human::isAlive() const
{
    return mIsAlive;
}

bool Human::isTall() const
{
    return mHeight > TALL_LIMIT;
}

void Human::setName(const std::string& name)
{
    mName = name;
}

void Human::setLocation(const std::string& location)
{
    mLocation = location;
}

void Human::setAge(int age)
{
    mCurrentAge = age;
}

void Human::setLifeSpan(int lifeSpan)
{
    mLifeSpan = lifeSpan;
}

void Human::setHeight(int height)
{
    mHeight = height;
}

void Human::setWeight(long long weight)
{
    mWeight = weight;
}

void Human::setGender(bool gender)
{
    mGender = gender;
}

void Human::setSalary(long long salary)
{
    mSalary = salary;
}

void Human::grow(int plusHeight)
{
    mHeight += plusHeight;
}

void Human::shorten(int minusHeight)
{
    mHeight -= minusHeight;
}

void Human::plump(long long plusWeight)
{
    mWeight += plusWeight;
}

void Human::thinOut(long long minusWeight)
{
    mWeight -= minusWeight;
}

void Human::raise(long long plusSalary)
{
    mSalary += plusSalary;
}

void Human::decrease(long long minusSalary)
{
    mSalary -= minusSalary;
}

void Human::getNewJob(long long salary)
{
    mSalary = salary;
}

void Human::getNewJob(const std::string& location, long long salary)
{
    mLocation = location;
    mSalary = salary;
}

void Human::mDefaultInit()
{
    mGenders.emplace_back("Female");
    mGenders.emplace_back("Male");
    for (int i = 0; i < (int)mGenders.size(); ++i)
    {
        std::string gender = mGenders[i];
        mGenderToNum[gender] = static_cast<bool>(i);
        mNumToGender[i] = gender;
    }
}

void Human::mDie()
{
    mIsAlive = false;
}

void Human::mReincarnate()
{
    mIsAlive = true;
}

void Human::mValidateData(int currentAge, int lifeSpan, int gender, int height, long long weight)
{
    if (currentAge < 0 || currentAge > lifeSpan) {
        mIsAlive = false;
    }
    if (gender > 1) {
        mGender = static_cast<bool>(rand() % 2);
    }
    if (height < 0) {
        mHeight = DEFAULT_ADULT_HEIGHT;
    }
    if (weight < 0) {
        mWeight = DEFAULT_ADULT_WEIGHT;
    }
}

std::istream& operator>>(std::istream& input, Human& next)
{
    std::cout << "Name: " << '\n';
    std::string name;
    input >> name;
    std::cout << "Location: " << '\n';
    std::string location;
    input >> location;
    std::cout << "Age: " << '\n';
    int age;
    input >> age;
    std::cout << "Gender: " << '\n';
    bool gender;
    input >> gender;
    std::cout << "Salary: " << '\n';
    long long salary;
    input >> salary;
    std::cout << "Height: " << '\n';
    int height;
    input >> height;
    std::cout << "Weight: " << '\n';
    long long weight;
    input >> weight;
    next = Human(name, location, age, height, weight, gender, salary/*, qualities*/);
    return input;
}

std::ostream &operator<<=(std::ostream &output, Human& next)
{
    output.clear();
    return operator<<(output, next);
}

std::istream &operator>>=(std::istream &input, Human& next)
{
    input.clear();
    return operator>>(input, next);
}

std::ostream& operator<<(std::ostream& output, Human& next)
{
    output << "Name: " << next.getName() << '\n';
    output << "Location: " << next.getLocation() << '\n';
    output << "Age: " << next.getAge() << '\n';
    output << "Gender: " << next.getGender() << '\n';
    output << "Height: " << next.getHeight() << '\n';
    output << "Weight: " << next.getWeight() << '\n';
    output << "Salary: " << next.getSalary() << '\n';
    return output;
}
