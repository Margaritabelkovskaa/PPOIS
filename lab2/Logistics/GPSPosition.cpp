#include "GPSPosition.h"
#include <cmath>
#include <sstream>
#include <iomanip>

GPSPosition::GPSPosition(double lat, double lon, double alt)
    : latitude(lat), longitude(lon), altitude(alt), timestamp("2024-01-01 00:00:00") {
}

double GPSPosition::calculateDistance(const GPSPosition& other) const {
    double latDiff = latitude - other.latitude;
    double lonDiff = longitude - other.longitude;
    return sqrt(latDiff * latDiff + lonDiff * lonDiff) * 111.0;
}

bool GPSPosition::isValid() const {
    return latitude >= -90 && latitude <= 90 &&
        longitude >= -180 && longitude <= 180;
}

std::string GPSPosition::toString() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(6)
        << "Lat: " << latitude << ", Lon: " << longitude;
    return ss.str();
}