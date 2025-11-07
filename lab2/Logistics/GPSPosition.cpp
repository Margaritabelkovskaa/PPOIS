#include "GPSPosition.h"
#include <cmath>
#include <sstream>
#include <iomanip>
namespace {
    const double MIN_LATITUDE = -90.0;
    const double MAX_LATITUDE = 90.0;
    const double MIN_LONGITUDE = -180.0;
    const double MAX_LONGITUDE = 180.0;
    const double KM_PER_DEGREE = 111.0;
}

GPSPosition::GPSPosition(double lat, double lon, double alt)
    : latitude(lat), longitude(lon), altitude(alt), timestamp("2024-01-01 00:00:00") {
}

double GPSPosition::calculateDistance(const GPSPosition& other) const {
    double latDiff = latitude - other.latitude;
    double lonDiff = longitude - other.longitude;
    return sqrt(latDiff * latDiff + lonDiff * lonDiff) * KM_PER_DEGREE;
}

bool GPSPosition::isValid() const {
    return latitude >= MIN_LATITUDE && latitude <= MAX_LATITUDE &&
           longitude >= MIN_LONGITUDE && longitude <= MAX_LONGITUDE;
}

std::string GPSPosition::toString() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(6)
        << "Lat: " << latitude << ", Lon: " << longitude;
    return ss.str();
}
