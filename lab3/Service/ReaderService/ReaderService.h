#ifndef READERSERVICE_H
#define READERSERVICE_H

#include "Reader.h"
#include "Loan.h"
#include "Fine.h"
#include <vector>
#include <memory>

class ReaderService {
private:
    vector<shared_ptr<Reader>> readers;
public:
    static bool canBorrow(const shared_ptr<Reader>& reader,
        const vector<shared_ptr<Loan>>& activeLoans,
        const vector<shared_ptr<Fine>>& unpaidFines);

    static bool hasOverdueLoans(const vector<shared_ptr<Loan>>& activeLoans);
    static int getAvailableSlots(const shared_ptr<Reader>& reader,
        const vector<shared_ptr<Loan>>& activeLoans);
    static double getTotalDebt(const vector<shared_ptr<Fine>>& fines);
    static bool hasSeriousFines(const vector<shared_ptr<Fine>>& fines);
    bool registerReader(const std::string& name, const std::string& contactInfo,
        const std::string& readerType = "standard");

    std::shared_ptr<Reader> getReader(int readerId) const;

    std::vector<std::shared_ptr<Reader>> getAllReaders() const;
    bool removeReader(int readerId);
};

#endif