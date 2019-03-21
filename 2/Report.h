#pragma once

#include <vector>
#include <string>

class Report
{
  public:
    Report();
    Report(int admissionNumber, const std::string& name, const std::vector<double>& vectorMarks);
    void readInfo(int admissionNumber, const std::string& name, const std::vector<double>& vectorMarks);
    void displayInfo() const;

  private:
    int mAdmissionNumber;
    std::string mName;
    std::vector<double> mVectorMarks;
    double mAverage;
    double mComputeAverage();
};