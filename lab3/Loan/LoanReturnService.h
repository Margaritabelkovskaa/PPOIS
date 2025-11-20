#ifndef LOANRETURNSERVICE_H
#define LOANRETURNSERVICE_H

#include "Loan.h"
#include "FineService.h"
#include <vector>
#include <memory>

using namespace std;

class LoanReturnService {
private:
    vector<shared_ptr<Loan>> activeLoans;
    shared_ptr<FineService> fineService;

public:
    LoanReturnService(shared_ptr<FineService> fineService);

    bool returnBook(int loanId, int overdueDays = 0);
    bool renewLoan(int loanId, int additionalDays = 7);

    vector<shared_ptr<Loan>> getOverdueLoans() const;

    void setFineService(shared_ptr<FineService> service);
    void addLoan(const shared_ptr<Loan>& loan);
    vector<shared_ptr<Loan>> getActiveLoans() const;
};

#endif