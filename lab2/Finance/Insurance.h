#ifndef INSURANCE_H
#define INSURANCE_H

#include <string>

class Vehicle;

class Insurance {
private:
    std::string policyNumber;
    Vehicle* insuredVehicle;
    std::string startDate;
    std::string endDate;
    double premium;
    double coverageAmount;
    std::string company;

public:
    Insurance(const std::string& policy, Vehicle* vehicle,
        const std::string& start, const std::string& end,
        double premium, double coverage, const std::string& company);

    bool isValid() const;
    double calculatePremium() const;
    bool isExpired() const;

    std::string getPolicyNumber() const { return policyNumber; }
    double getCoverageAmount() const { return coverageAmount; }
};

#endif