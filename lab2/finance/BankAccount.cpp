#include "BankAccount.h"

BankAccount::BankAccount(const std::string& accNumber, const std::string& bank,
    double initialBalance, const std::string& curr)
    : accountNumber(accNumber), bankName(bank), balance(initialBalance), currency(curr) {
}

bool BankAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void BankAccount::deposit(double amount) {
    balance += amount;
}

bool BankAccount::transfer(BankAccount* toAccount, double amount) {
    if (withdraw(amount)) {
        toAccount->deposit(amount);
        return true;
    }
    return false;
}

bool BankAccount::hasSufficientFunds(double amount) const {
    return balance >= amount;
}