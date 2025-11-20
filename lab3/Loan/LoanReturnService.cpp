#include "LoanReturnService.h"

LoanReturnService::LoanReturnService(shared_ptr<FineService> fineService)
    : fineService(fineService) {
}

bool LoanReturnService::returnBook(int loanId, int overdueDays) {
    for (auto& loan : activeLoans) {
        if (loan->getLoanId() == loanId && !loan->getIsReturned()) {
            loan->returnBook();

            // Если есть просрочка - создаем штраф
            if (overdueDays > 0 && fineService) {
                double fineAmount = overdueDays * 10.0; // Базовая ставка
                fineService->createFine(loan->getReader(), fineAmount, "overdue", loan);
            }

            return true;
        }
    }
    return false;
}

bool LoanReturnService::renewLoan(int loanId, int additionalDays) {
    for (auto& loan : activeLoans) {
        if (loan->getLoanId() == loanId && loan->canBeRenewed()) {
            loan->renewLoan(additionalDays);
            return true;
        }
    }
    return false;
}

vector<shared_ptr<Loan>> LoanReturnService::getOverdueLoans() const {
    vector<shared_ptr<Loan>> result;
    for (const auto& loan : activeLoans) {
        if (loan && loan->isOverdue()) {
            result.push_back(loan);
        }
    }
    return result;
}

void LoanReturnService::setFineService(shared_ptr<FineService> service) {
    fineService = service;
}

void LoanReturnService::addLoan(const shared_ptr<Loan>& loan) {
    if (loan) {
        activeLoans.push_back(loan);
    }
}

vector<shared_ptr<Loan>> LoanReturnService::getActiveLoans() const {
    return activeLoans;
}