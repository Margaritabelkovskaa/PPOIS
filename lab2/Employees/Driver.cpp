#include "Driver.h"
#include "DrivingLicense.h"
#include "Vehicle.h"

Driver::Driver(const std::string& name, const std::string& phone,
    DrivingLicense* license, double salary)
    : Employee("DRV_001", name, phone, "", "Driver", salary * 160, "2024-01-01", "Transport"),
      license(license), assignedVehicle(nullptr), 
      salaryPerHour(salary), isAvailable(true) {
}

Driver::~Driver() {
}

void Driver::assignVehicle(Vehicle* vehicle) {
    assignedVehicle = vehicle;
    isAvailable = false;
}

void Driver::setAvailability(bool available) {
    isAvailable = available;
}

double Driver::calculateSalary(int hours) const {
    return hours * salaryPerHour;
}
