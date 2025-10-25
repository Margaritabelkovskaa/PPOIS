#ifndef ORDER_H
#define ORDER_H

#include <string>

class Client;
class Cargo;
class Driver;
class Vehicle;

class Order {
private:
    int orderId;
    Client* client;
    Cargo* cargo;
    Driver* driver;
    Vehicle* vehicle;
    std::string fromAddress;
    std::string toAddress;
    std::string orderDate;      
    std::string deliveryDate;   
    double cost;
    std::string status;

public:
    Order(int id, Client* client, Cargo* cargo, const std::string& from,
        const std::string& to, double cost);
    ~Order();

    void assignDriver(Driver* driver);
    void assignVehicle(Vehicle* vehicle);
    void updateStatus(const std::string& newStatus);
    bool isDelivered() const;

    int getOrderId() const { return orderId; }
    double getCost() const { return cost; }
    std::string getStatus() const { return status; }
    std::string getOrigin() const { return fromAddress; }
    std::string getDestination() const { return toAddress; }
    Client* getClient() const { return client; }
    Cargo* getCargo() const { return cargo; }
};

#endif