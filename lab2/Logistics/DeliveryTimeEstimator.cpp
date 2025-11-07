#include "DeliveryTimeEstimator.h"

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
