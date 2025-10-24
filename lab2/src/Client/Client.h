#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

class Client {
private:
    std::string name;
    std::string phone;
    double balance;

public:
    Client();
    Client(const std::string& name, const std::string& phone);

    void inputUserData();
    void addMoney(double amount);
    bool pay(double amount);
    bool makePayment(double amount);

    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }
    double getBalance() const { return balance; }
};

#endif