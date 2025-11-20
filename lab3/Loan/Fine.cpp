#include "Fine.h"
#include "Reader.h"
#include "Loan.h"

Fine::Fine(int id, double amount, const string& reason,
    const shared_ptr<Reader>& reader, const shared_ptr<Loan>& loan)
    : fineId(id), amount(amount), reason(reason),
    isPaid(false), reader(reader), relatedLoan(loan) {
}

bool Fine::canBeWaived() const {
    return !isSeriousFine();
}

bool Fine::isSeriousFine() const {
    return reason == "lost" || reason == "severe_damage";
}

string Fine::getFineType() const {
    return reason;
}

void Fine::markAsPaid() {
    isPaid = true;
}

void Fine::updateAmount(double newAmount) {
    if (newAmount >= 0) {
        amount = newAmount;
    }
}

int Fine::getFineId() const { return fineId; }
double Fine::getAmount() const { return amount; }
string Fine::getReason() const { return reason; }
bool Fine::getIsPaid() const { return isPaid; }
shared_ptr<Reader> Fine::getReader() const { return reader; }
shared_ptr<Loan> Fine::getRelatedLoan() const { return relatedLoan; }