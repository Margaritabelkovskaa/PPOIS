#include "Client.h"

Client::Client() : balance(0) {
    inputUserData();
}

Client::Client(const std::string& name, const std::string& phone)
    : name(name), phone(phone), balance(0) {
}

void Client::inputUserData() {
    std::cout << "Enter client name: ";
    std::getline(std::cin, name);

    std::cout << "Enter client phone: ";
    std::getline(std::cin, phone);
}

void Client::addMoney(double amount) {
    balance += amount;
}

bool Client::pay(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

bool Client::makePayment(double amount) {
    return pay(amount);
}