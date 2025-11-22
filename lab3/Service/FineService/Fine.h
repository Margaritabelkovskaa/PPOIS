#ifndef FINE_H
#define FINE_H

#include <string>
#include <memory>

using namespace std;

class Reader;
class Loan;

class Fine {
private:
    int fineId;
    double amount;
    string reason;
    bool isPaid;
    shared_ptr<Reader> reader;
    shared_ptr<Loan> relatedLoan;

public:
    Fine(int id, double amount, const string& reason,
        const shared_ptr<Reader>& reader, const shared_ptr<Loan>& loan = nullptr);

    bool canBeWaived() const;
    bool isSeriousFine() const;
    string getFineType() const;

    void markAsPaid();
    void updateAmount(double newAmount);

    int getFineId() const;
    double getAmount() const;
    string getReason() const;
    bool getIsPaid() const;
    shared_ptr<Reader> getReader() const;
    shared_ptr<Loan> getRelatedLoan() const;
};

#endif