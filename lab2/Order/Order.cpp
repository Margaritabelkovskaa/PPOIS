#include "Order.h"
#include "Client.h"
#include "Cargo.h"
#include "Driver.h"
#include "Vehicle.h"

Order::Order(int id, Client* client, Cargo* cargo, const std::string& from,
    const std::string& to, double cost)
    : orderId(id), client(client), cargo(cargo), driver(nullptr), vehicle(nullptr),
    fromAddress(from), toAddress(to), orderDate("2024-01-01"), cost(cost), status("Pending") {
}

Order::~Order() {
    // �� ������� cargo, ��� ��� �� ��������� � main()
}

void Order::assignDriver(Driver* driver) {
    this->driver = driver;
    status = "Assigned";
}

void Order::assignVehicle(Vehicle* vehicle) {
    this->vehicle = vehicle;
    status = "Ready";
}

void Order::updateStatus(const std::string& newStatus) {
    status = newStatus;
    if (newStatus == "Delivered") {
        deliveryDate = "2024-01-05"; // ������������� ���� ��������
    }
}

bool Order::isDelivered() const {
    return status == "Delivered";
}