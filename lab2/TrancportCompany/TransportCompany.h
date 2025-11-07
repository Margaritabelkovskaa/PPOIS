#ifndef TRANSPORTCOMPANY_H
#define TRANSPORTCOMPANY_H

#include <vector>
#include <string>

class Client;
class Driver;
class Vehicle;
class Order;

class TransportCompany {
private:
    std::string companyName;
    std::vector<Client*> clients;
    std::vector<Driver*> drivers;
    std::vector<Vehicle*> vehicles;
    std::vector<Order*> orders;
    double companyBalance;

public:
    TransportCompany(const std::string& name);
    ~TransportCompany();

    void addClient(Client* client);
    void addDriver(Driver* driver);
    void addVehicle(Vehicle* vehicle);
    void createOrder(Order* order);
    double calculateDailyRevenue() const;
    void processAllPayments();

    std::string getCompanyName() const { return companyName; }
    int getClientsCount() const { return clients.size(); }
    int getDriversCount() const { return drivers.size(); }
    int getVehiclesCount() const { return vehicles.size(); }
};

#endif
