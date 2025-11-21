#include "Reader.h"

Reader::Reader(int id, const string& name, const string& contactInfo,
    const string& readerType)
    : readerId(id), name(name), contactInfo(contactInfo),
    readerType(readerType), maxLoanLimit(5) {

    if (readerType == "premium") maxLoanLimit = 10;
    if (readerType == "vip") maxLoanLimit = 20;
}

int Reader::getReaderId() const { return readerId; }
string Reader::getName() const { return name; }
string Reader::getContactInfo() const { return contactInfo; }
string Reader::getReaderType() const { return readerType; }
int Reader::getMaxLoanLimit() const { return maxLoanLimit; }
shared_ptr<BankAccount> Reader::getBankAccount() const { return bankAccount; }

void Reader::setContactInfo(const string& contact) {
    contactInfo = contact;
}

void Reader::setUpgradeToPremium() {
    readerType = "premium";
    maxLoanLimit = 10;
}

bool Reader::isValid() const {
    return readerId > 0 && !name.empty() && !contactInfo.empty();
}

void Reader::setBankAccount(const shared_ptr<BankAccount>& account) {
    bankAccount = account;
}

bool Reader::hasBankAccount() const {
    return bankAccount != nullptr && bankAccount->getIsActive();
}

bool Reader::canPayFine(double amount) const {
    return hasBankAccount() && bankAccount->canWithdraw(amount);
}