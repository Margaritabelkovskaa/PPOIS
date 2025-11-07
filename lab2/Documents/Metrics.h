#ifndef METRICS_H
#define METRICS_H

#include <string>

class PerformanceMetric {
private:
    std::string metricId;
    std::string metricType;
    double value;
    std::string measurementDate;

public:
    PerformanceMetric(const std::string& id, const std::string& type, double value, const std::string& date);

    bool isTargetAchieved(double target) const;
    double calculateImprovement(double previousValue) const;
    std::string getPerformanceLevel() const;

    std::string getMetricType() const { return metricType; }
    double getValue() const { return value; }
};

class FuelConsumption {
private:
    std::string recordId;
    double liters;
    double cost;
    std::string consumptionDate;

public:
    FuelConsumption(const std::string& id, double liters, double cost, const std::string& date);

    double calculateCostPerLiter() const;
    double calculateFuelEfficiency(double distance) const;
    bool isHighConsumption() const;

    double getLiters() const { return liters; }
    double getCost() const { return cost; }
};

class TrafficInfo {
private:
    std::string infoId;
    double trafficDelay;
    std::string trafficCondition;

public:
    TrafficInfo(const std::string& id, double delay, const std::string& condition);

    double calculateAdditionalTime() const;
    bool isSevereTraffic() const;
    void updateTrafficCondition(const std::string& newCondition);

    double getTrafficDelay() const { return trafficDelay; }
    std::string getTrafficCondition() const { return trafficCondition; }
};

#endif