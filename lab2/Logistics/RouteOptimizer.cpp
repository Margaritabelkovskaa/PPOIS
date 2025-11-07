#include "RouteOptimizer.h"
#include <algorithm>

namespace RouteConstants {
    const double DEFAULT_CALCULATION_SPEED = 60.0; 
}

RouteOptimizer::RouteOptimizer(const std::vector<GPSPosition>& points, bool avoidTraffic)
    : waypoints(points), trafficAvoidance(avoidTraffic), totalDistance(0.0), estimatedTime(0.0) {
}

void RouteOptimizer::calculateOptimalRoute() {
    totalDistance = 0.0;
    for (size_t i = 1; i < waypoints.size(); ++i) {
        totalDistance += waypoints[i - 1].calculateDistance(waypoints[i]);
    }
    estimatedTime = totalDistance / RouteConstants::DEFAULT_CALCULATION_SPEED;
}

void RouteOptimizer::addWaypoint(const GPSPosition& point) {
    waypoints.push_back(point);
}

void RouteOptimizer::removeWaypoint(int index) {
    if (index >= 0 && index < waypoints.size()) {
        waypoints.erase(waypoints.begin() + index);
    }
}
