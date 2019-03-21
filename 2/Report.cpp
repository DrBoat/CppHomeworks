#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cassert>

#include "Report.h"

using std::cout;
using std::endl;

const int MARKS_SIZE = 5;
const int ADMISSION_NUMBER_LENGTH = 4;
const int NAME_LENGTH = 20;

double Report::mComputeAverage()
{
    double sumOfMarks = 0;
    for (auto i: mVectorMarks)
    {
        sumOfMarks += i;
    }
    return (double)(sumOfMarks / MARKS_SIZE);
}

Report::Report() : mAdmissionNumber(0), mName(""), mAverage(0) {};

Report::Report(int admissionNumber, const std::string& name,
               const std::vector<double>& vectorMarks)
{
    Report::readInfo(admissionNumber, name, vectorMarks);
}

void Report::readInfo(int admissionNumber, const std::string& name,
                      const std::vector<double>& vectorMarks)
{
    bool isShort = admissionNumber < (int)pow(10, (ADMISSION_NUMBER_LENGTH - 1));
    if (isShort)
    {
        std::stringstream e;
        e << "Too short Admission Number (" << admissionNumber;
        e << "). Try again. " << "mAdmissionNumber should be 4 digits" << endl;
        throw e.str();
    }
    bool isLong = admissionNumber >= (int)pow(10, (ADMISSION_NUMBER_LENGTH));
    if (isLong)
    {
        std::stringstream e;
        e << "Too long Admission Number (" << admissionNumber;
        e << "). Try again. " << "mAdmissionNumber should be 4 digits" << endl;
        throw e.str();
    }
    
    if (name.size() > NAME_LENGTH)
    {
        std::stringstream e;
        e << "Too long Name (" << name << "). Try again. ";
        e << "Max length is 20 characters" << endl;
        throw e.str();
    }
    
    if (vectorMarks.size() != MARKS_SIZE)
    {
        std::stringstream e;
        e << "Invalid amount of Marks (" << vectorMarks.size();
        e << "). Try again. " << "Valid amount of Marks is 5" << endl;
        throw e.str();
    }
        mAdmissionNumber = admissionNumber;
        mName = name;
        mVectorMarks = vectorMarks;
        mAverage = mComputeAverage();
        return;
}

void Report::displayInfo() const
{
    if (mAdmissionNumber == 0)
    {
        cout << "Student isn't initialized" << endl;
        return;
    }

    cout << "Admission Number: " << mAdmissionNumber<< endl;
    cout << "Name: " << mName << endl;

    cout << "Marks:";
    for(auto i : mVectorMarks)
    {
        cout << ' ' << i;
    }
    cout << endl;

    cout << "Average: " << mAverage << endl;
    return;
}

int main()
{
    Report me;
    std::vector<double> vectorMarks;
    vectorMarks.push_back(4.5);
    vectorMarks.push_back(3.7);
    vectorMarks.push_back(4.2);
    vectorMarks.push_back(4.6);
    vectorMarks.push_back(3.5);

    try
    {
      	me.readInfo(21861, "Vozleev Yury", vectorMarks);
    }
    catch (std::string e)
    {
      	cout << e;
    }
    me.displayInfo();
}