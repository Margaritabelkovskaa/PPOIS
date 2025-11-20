
#ifndef LOANSERVICE_H
#define LOANSERVICE_H

#include "Loan.h"
#include "Reader.h"
#include "Book.h"
#include "Employee.h"
#include "ReaderService.h"
#include <vector>
#include <memory>

using namespace std;

class LoanService {
private:
    vector<shared_ptr<Loan>> activeLoans;

public:
    shared_ptr<Loan> createLoan(const shared_ptr<Reader>& reader,
        const shared_ptr<Book>& book,
        const shared_ptr<Employee>& employee,
        int durationDays = 14);

    bool canBorrowBook(const shared_ptr<Reader>& reader, const shared_ptr<Book>& book) const;
    vector<shared_ptr<Loan>> getReaderLoans(int readerId) const;
    vector<shared_ptr<Loan>> getOverdueLoans() const;

    void addLoan(const shared_ptr<Loan>& loan);
    const vector<shared_ptr<Loan>>& getActiveLoans() const;
};

#endif