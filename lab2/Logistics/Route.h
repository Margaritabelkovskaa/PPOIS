#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>
#include "Address.h"
#include "GPSPosition.h"

class Route {
private:
    std::string routeId;
    Address* startPoint;
    Address* endPoint;
    std::vector<GPSPosition*> waypoints;
    double totalDistance;
    double estimatedTime;

public:
    Route(const std::string& id, Address* start, Address* end);
    ~Route();

    void addWaypoint(GPSPosition* point);
    void calculateRoute();
    double calculateETA(double speed) const;

    std::string getRouteId() const { return routeId; }
    double getTotalDistance() const { return totalDistance; }
    double getEstimatedTime() const { return estimatedTime; }
};

#endif
