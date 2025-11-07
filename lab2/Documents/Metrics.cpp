#include "Metrics.h"

PerformanceMetric::PerformanceMetric(const std::string& id, const std::string& type, double value, const std::string& date)
    : metricId(id), metricType(type), value(value), measurementDate(date) {
}

bool PerformanceMetric::isTargetAchieved(double target) const {
    return value >= target;
}

double PerformanceMetric::calculateImprovement(double previousValue) const {
    return value - previousValue;
}

std::string PerformanceMetric::getPerformanceLevel() const {
    if (value > 90) return "Excellent";
    if (value > 70) return "Good";
    return "Needs Improvement";
}

// FuelConsumption методы
FuelConsumption::FuelConsumption(const std::string& id, double liters, double cost, const std::string& date)
    : recordId(id), liters(liters), cost(cost), consumptionDate(date) {
}

double FuelConsumption::calculateCostPerLiter() const {
    return cost / liters;
}

double FuelConsumption::calculateFuelEfficiency(double distance) const {
    return distance / liters;
}

bool FuelConsumption::isHighConsumption() const {
    return liters > 100.0;
}

// TrafficInfo методы
TrafficInfo::TrafficInfo(const std::string& id, double delay, const std::string& condition)
    : infoId(id), trafficDelay(delay), trafficCondition(condition) {
}

double TrafficInfo::calculateAdditionalTime() const {
    return trafficDelay / 60.0;
}

bool TrafficInfo::isSevereTraffic() const {
    return trafficDelay > 30.0;
}

void TrafficInfo::updateTrafficCondition(const std::string& newCondition) {
    trafficCondition = newCondition;
}