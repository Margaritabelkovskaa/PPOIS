#include "Insurance.h"
#include "Vehicle.h"

Insurance::Insurance(const std::string& policy, Vehicle* vehicle,
    const std::string& start, const std::string& end,
    double premium, double coverage, const std::string& company)
    : policyNumber(policy), insuredVehicle(vehicle), startDate(start),
    endDate(end), premium(premium), coverageAmount(coverage), company(company) {
}

bool Insurance::isValid() const {
    return true; // Упрощенная проверка
}

double Insurance::calculatePremium() const {
    return premium;
}

bool Insurance::isExpired() const {
    return false; // Упрощенная проверка
}