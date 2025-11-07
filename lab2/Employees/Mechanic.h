#ifndef MECHANIC_H
#define MECHANIC_H

#include <string>
#include <vector>

class Vehicle;
class MaintenanceRecord;

class Mechanic {
private:
    std::string name;
    std::string specialization;
    std::vector<Vehicle*> assignedVehicles;
    std::vector<MaintenanceRecord*> maintenanceHistory;

public:
    Mechanic(const std::string& name, const std::string& specialization);

    void performMaintenance(Vehicle* vehicle, const std::string& description);
    bool diagnoseProblem(Vehicle* vehicle) const;
    void addVehicleToMaintenance(Vehicle* vehicle);

    std::string getName() const { return name; }
    std::string getSpecialization() const { return specialization; }
};

#endif
