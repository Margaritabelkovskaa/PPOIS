#include "LoanService.h"

shared_ptr<Loan> LoanService::createLoan(const shared_ptr<Reader>& reader,
    const shared_ptr<Book>& book,
    const shared_ptr<Employee>& employee,
    int durationDays) {

    if (!reader || !book || !employee) return nullptr;
    if (!book->canBeBorrowed()) return nullptr;

    // Получаем активные выдачи читателя
    vector<shared_ptr<Loan>> readerLoans = getReaderLoans(reader->getReaderId());

    // Проверяем может ли читатель взять книгу
    vector<shared_ptr<Fine>> emptyFines; // В реальности получать из FineService
    if (!ReaderService::canBorrow(reader, readerLoans, emptyFines)) {
        return nullptr;
    }

    int loanId = activeLoans.empty() ? 1 : activeLoans.back()->getLoanId() + 1;
    auto loan = make_shared<Loan>(loanId, reader, book, employee, durationDays);
    activeLoans.push_back(loan);

    return loan;
}

bool LoanService::canBorrowBook(const shared_ptr<Reader>& reader, const shared_ptr<Book>& book) const {
    if (!reader || !book) return false;
    if (!book->canBeBorrowed()) return false;

    vector<shared_ptr<Loan>> readerLoans = getReaderLoans(reader->getReaderId());
    vector<shared_ptr<Fine>> emptyFines;

    return ReaderService::canBorrow(reader, readerLoans, emptyFines);
}

vector<shared_ptr<Loan>> LoanService::getReaderLoans(int readerId) const {
    vector<shared_ptr<Loan>> result;
    for (const auto& loan : activeLoans) {
        if (loan && loan->getReader()->getReaderId() == readerId && !loan->getIsReturned()) {
            result.push_back(loan);
        }
    }
    return result;
}

vector<shared_ptr<Loan>> LoanService::getOverdueLoans() const {
    vector<shared_ptr<Loan>> result;
    for (const auto& loan : activeLoans) {
        if (loan && loan->isOverdue()) {
            result.push_back(loan);
        }
    }
    return result;
}

void LoanService::addLoan(const shared_ptr<Loan>& loan) {
    if (loan) {
        activeLoans.push_back(loan);
    }
}

const vector<shared_ptr<Loan>>& LoanService::getActiveLoans() const {
    return activeLoans;
}