#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class TransportException : public std::exception {
private:
    std::string message;
public:
    explicit TransportException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InsufficientFundsException : public TransportException {
public:
    InsufficientFundsException();
};

class InvalidClientDataException : public TransportException {
public:
    explicit InvalidClientDataException(const std::string& field);
};

class OrderNotFoundException : public TransportException {
public:
    explicit OrderNotFoundException(int orderId);
};

class InvalidOrderDataException : public TransportException {
public:
    explicit InvalidOrderDataException(const std::string& field);
};

class InvalidCargoDataException : public TransportException {
public:
    explicit InvalidCargoDataException(const std::string& field);
};

class CargoOverweightException : public TransportException {
public:
    CargoOverweightException(double weight, double maxWeight);
};

class VehicleOverloadException : public TransportException {
public:
    VehicleOverloadException(double load, double capacity);
};

class VehicleNotAvailableException : public TransportException {
public:
    VehicleNotAvailableException();
};

class DriverNotAvailableException : public TransportException {
public:
    DriverNotAvailableException();
};

class InvalidLicenseException : public TransportException {
public:
    InvalidLicenseException();
};

class RouteException : public TransportException {
public:
    explicit RouteException(const std::string& reason);
};

#endif