#include "Route.h"

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
    // Простой расчет расстояния
    if (startPoint->getGPSPosition() && endPoint->getGPSPosition()) {
        totalDistance = startPoint->getGPSPosition()->calculateDistance(*endPoint->getGPSPosition());
        estimatedTime = totalDistance / 60.0; // часов при скорости 60 км/ч
    }
}

double Route::calculateETA(double speed) const {
    return totalDistance / speed;
}