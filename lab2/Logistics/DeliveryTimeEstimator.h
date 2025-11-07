#ifndef DELIVERYTIMEESTIMATOR_H
#define DELIVERYTIMEESTIMATOR_H

class DeliveryTimeEstimator {
private:
    double averageSpeed;
    double loadingUnloadingTime;
    double trafficCoefficient;

public:
    DeliveryTimeEstimator(double avgSpeed, double loadTime);

    double estimateDeliveryTime(double distance, int stops = 1) const;
    void adjustForTraffic(double coefficient);
    void setLoadingTime(double time);

    double getAverageSpeed() const { return averageSpeed; }
};

#endif
