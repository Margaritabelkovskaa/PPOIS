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
    // ������� ������ ����������
    if (startPoint->getGPSPosition() && endPoint->getGPSPosition()) {
        totalDistance = startPoint->getGPSPosition()->calculateDistance(*endPoint->getGPSPosition());
        estimatedTime = totalDistance / 60.0; // ����� ��� �������� 60 ��/�
    }
}

double Route::calculateETA(double speed) const {
    return totalDistance / speed;
}