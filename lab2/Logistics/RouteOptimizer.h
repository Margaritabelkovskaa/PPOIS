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

#endif

