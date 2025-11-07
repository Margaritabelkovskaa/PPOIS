#ifndef GPSPOSITION_H
#define GPSPOSITION_H

#include <string>

class GPSPosition {
private:
    double latitude;
    double longitude;
    double altitude;
    std::string timestamp;

public:
    GPSPosition(double lat, double lon, double alt = 0.0);

    double calculateDistance(const GPSPosition& other) const;
    bool isValid() const;
    std::string toString() const;

    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
};

#endif
