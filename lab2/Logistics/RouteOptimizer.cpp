#include "RouteOptimizer.h"
#include <algorithm>
#include <cmath>

namespace {
    const double OPTIMIZATION_SPEED_KMH = 60.0;
    const double MAX_OPTIMAL_SPEED_KMH = 80.0;
    const double BASE_OPTIMAL_SPEED_KMH = 60.0;
    const double SPEED_DISTANCE_FACTOR = 0.01;
    const double DISTANCE_DIVISOR = 100.0;
}


RouteOptimizer::RouteOptimizer(const std::vector<GPSPosition>& points, bool avoidTraffic)
    : waypoints(points), trafficAvoidance(avoidTraffic), totalDistance(0.0), estimatedTime(0.0) {
}

void RouteOptimizer::calculateOptimalRoute() {
    totalDistance = 0.0;
    for (size_t i = 1; i < waypoints.size(); ++i) {
        totalDistance += waypoints[i - 1].calculateDistance(waypoints[i]);
    }
    estimatedTime = totalDistance / OPTIMIZATION_SPEED_KMH;
}

void RouteOptimizer::addWaypoint(const GPSPosition& point) {
    waypoints.push_back(point);
}

void RouteOptimizer::removeWaypoint(int index) {
    if (index >= 0 && index < waypoints.size()) {
        waypoints.erase(waypoints.begin() + index);
    }
}

// FuelCalculator
FuelCalculator::FuelCalculator(double consumption, double fuelPrice)
    : baseFuelConsumption(consumption), currentFuelPrice(fuelPrice), vehicleLoadFactor(1.0) {
}

double FuelCalculator::calculateFuelCost(double distance) const {
    double fuelNeeded = (baseFuelConsumption * distance / DISTANCE_DIVISOR) * vehicleLoadFactor;
    return fuelNeeded * currentFuelPrice;
}

double FuelCalculator::calculateOptimalSpeed(double distance) const {
    return std::min(MAX_OPTIMAL_SPEED_KMH, 
                   BASE_OPTIMAL_SPEED_KMH + distance * SPEED_DISTANCE_FACTOR);
}

void FuelCalculator::updateFuelPrice(double newPrice) {
    currentFuelPrice = newPrice;
}

// DeliveryTimeEstimator
DeliveryTimeEstimator::DeliveryTimeEstimator(double avgSpeed, double loadTime)
    : averageSpeed(avgSpeed), loadingUnloadingTime(loadTime), trafficCoefficient(1.0) {
}

double DeliveryTimeEstimator::estimateDeliveryTime(double distance, int stops) const {
    double travelTime = distance / averageSpeed * trafficCoefficient;
    double handlingTime = stops * loadingUnloadingTime;
    return travelTime + handlingTime;
}

void DeliveryTimeEstimator::adjustForTraffic(double coefficient) {
    trafficCoefficient = coefficient;
}

void DeliveryTimeEstimator::setLoadingTime(double time) {
    loadingUnloadingTime = time;
}
