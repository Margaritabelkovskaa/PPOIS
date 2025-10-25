#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "Employee.h"
#include "DrivingLicense.h"
#include "Vehicle.h"

class Driver : public Employee {
private:
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
    
    // Переопределение виртуальных методов
    double calculateBonus() const override;
    void displayInfo() const override;

    // Геттеры
    DrivingLicense* getLicense() const { return license; }
    Vehicle* getAssignedVehicle() const { return assignedVehicle; }
    double getSalaryPerHour() const { return salaryPerHour; }
    bool getIsAvailable() const { return isAvailable; }
};

#endif
