#include "Exceptions.h"

InsufficientFundsException::InsufficientFundsException() :
    TransportException("Insufficient funds for payment") {
}

InvalidClientDataException::InvalidClientDataException(const std::string& field) :
    TransportException("Invalid client data: " + field) {
}

OrderNotFoundException::OrderNotFoundException(int orderId) :
    TransportException("Order not found with ID: " + std::to_string(orderId)) {
}

InvalidOrderDataException::InvalidOrderDataException(const std::string& field) :
    TransportException("Invalid order data: " + field) {
}

InvalidCargoDataException::InvalidCargoDataException(const std::string& field) :
    TransportException("Invalid cargo data: " + field) {
}

CargoOverweightException::CargoOverweightException(double weight, double maxWeight) :
    TransportException("Cargo weight " + std::to_string(weight) +
        " exceeds maximum " + std::to_string(maxWeight)) {
}

VehicleOverloadException::VehicleOverloadException(double load, double capacity) :
    TransportException("Vehicle overload: " + std::to_string(load) +
        "kg exceeds capacity " + std::to_string(capacity) + "kg") {
}

VehicleNotAvailableException::VehicleNotAvailableException() :
    TransportException("Vehicle is not available") {
}

DriverNotAvailableException::DriverNotAvailableException() :
    TransportException("Driver is not available") {
}

InvalidLicenseException::InvalidLicenseException() :
    TransportException("Driver license is invalid or expired") {
}

RouteException::RouteException(const std::string& reason) :
    TransportException("Route error: " + reason) {
}