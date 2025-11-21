
#ifndef READER_H
#define READER_H

#include <string>
#include <memory>
#include "BankAccount.h"

using namespace std;

class Reader {
private:
    int readerId;
    string name;
    string contactInfo;
    string readerType; // "standard", "premium", "vip"
    int maxLoanLimit;
    shared_ptr<BankAccount> bankAccount;

public:
    Reader(int id, const string& name, const string& contactInfo,
        const string& readerType = "standard");

    int getReaderId() const;
    string getName() const;
    string getContactInfo() const;
    string getReaderType() const;
    int getMaxLoanLimit() const;
    shared_ptr<BankAccount> getBankAccount() const;

    void setContactInfo(const string& contact);
    void setUpgradeToPremium();
    bool isValid() const;

    void setBankAccount(const shared_ptr<BankAccount>& account);
    bool hasBankAccount() const;
    bool canPayFine(double amount) const;
};

#endif