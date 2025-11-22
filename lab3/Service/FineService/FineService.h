#ifndef FINESERVICE_H
#define FINESERVICE_H

#include "Fine.h"
#include "Reader.h"
#include "Loan.h"
#include <vector>
#include <memory>

using namespace std;

class FineService {
private:
    vector<shared_ptr<Fine>> fines;

public:
    shared_ptr<Fine> createFine(const shared_ptr<Reader>& reader,
        double amount, const string& reason,
        const shared_ptr<Loan>& loan = nullptr);

    vector<shared_ptr<Fine>> getReaderFines(int readerId) const;
    vector<shared_ptr<Fine>> getUnpaidFines() const;
    vector<shared_ptr<Fine>> getSeriousFines() const;
    double calculateTotalDebt(int readerId) const;

    bool payFine(int fineId);
    bool waiveFine(int fineId);

    void addFine(const shared_ptr<Fine>& fine);
    const vector<shared_ptr<Fine>>& getAllFines() const;
};

#endif