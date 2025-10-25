#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "DrivingLicense.h"
#include "Vehicle.h"

class Driver {
private:
    std::string name;
    std::string phone;
    DrivingLicense* license;
    Vehicle* assignedVehicle;
    double salaryPerHour;
    bool isAvailable;

public:
    Driver(const std::string& name, const std::string& phone,
        DrivingLicense* license, double salary);
    ~Driver();

    void assignVehicle(Vehicle* vehicle);
    void setAvailability(bool available);
    double calculateSalary(int hours) const;

    // цЕРРЕПШ
    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    DrivingLicense* getLicense() const { return license; }
    Vehicle* getAssignedVehicle() const { return assignedVehicle; }
    double getSalaryPerHour() const { return salaryPerHour; }
    bool getIsAvailable() const { return isAvailable; }  // днаюбхрэ щрнр лернд

};

#endif