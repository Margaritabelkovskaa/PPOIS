#ifndef ROUTEOPTIMIZER_H
#define ROUTEOPTIMIZER_H

#include <vector>
#include <string>
#include "GPSPosition.h"

class RouteOptimizer {
private:
    std::vector<GPSPosition> waypoints;
    double totalDistance;
    double estimatedTime;
    bool trafficAvoidance;

public:
    RouteOptimizer(const std::vector<GPSPosition>& points, bool avoidTraffic = true);

    void calculateOptimalRoute();
    void addWaypoint(const GPSPosition& point);
    void removeWaypoint(int index);

    double getTotalDistance() const { return totalDistance; }
    double getEstimatedTime() const { return estimatedTime; }
    std::vector<GPSPosition> getWaypoints() const { return waypoints; }
};

class FuelCalculator {
private:
    double baseFuelConsumption;
    double currentFuelPrice;
    double vehicleLoadFactor;

public:
    FuelCalculator(double consumption, double fuelPrice);

    double calculateFuelCost(double distance) const;
    double calculateOptimalSpeed(double distance) const;
    void updateFuelPrice(double newPrice);

    double getCurrentFuelPrice() const { return currentFuelPrice; }
};

class DeliveryTimeEstimator {
private:
    double averageSpeed;
    double loadingUnloadingTime;
    double trafficCoefficient;

public:
    DeliveryTimeEstimator(double avgSpeed = 60.0, double loadTime = 0.5);

    double estimateDeliveryTime(double distance, int stops = 1) const;
    void adjustForTraffic(double coefficient);
    void setLoadingTime(double time);

    double getAverageSpeed() const { return averageSpeed; }
};

#endif
