#include "Route.h"

namespace {
    const double DEFAULT_AVERAGE_SPEED_KMH = 60.0;
}

Route::Route(const std::string& id, Address* start, Address* end)
    : routeId(id), startPoint(start), endPoint(end), totalDistance(0), estimatedTime(0) {
}

Route::~Route() {
    delete startPoint;
    delete endPoint;
    for (auto point : waypoints) {
        delete point;
    }
}

void Route::addWaypoint(GPSPosition* point) {
    waypoints.push_back(point);
}

void Route::calculateRoute() {
    if (startPoint->getGPSPosition() && endPoint->getGPSPosition()) {
        totalDistance = startPoint->getGPSPosition()->calculateDistance(*endPoint->getGPSPosition());
        estimatedTime = totalDistance / DEFAULT_AVERAGE_SPEED_KMH;
    }
}

double Route::calculateETA(double speed) const {
    if (speed <= 0) {
        speed = DEFAULT_AVERAGE_SPEED_KMH;
    }
    return totalDistance / speed;
}
