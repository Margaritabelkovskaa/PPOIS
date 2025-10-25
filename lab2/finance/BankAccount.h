#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string bankName;
    double balance;
    std::string currency;

public:
    BankAccount(const std::string& accNumber, const std::string& bank,
        double initialBalance, const std::string& curr = "USD");

    bool withdraw(double amount);
    void deposit(double amount);
    bool transfer(BankAccount* toAccount, double amount);
    bool hasSufficientFunds(double amount) const;

    std::string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
};

#endif