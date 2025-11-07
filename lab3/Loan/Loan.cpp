#include "Loan.h"
#include "Reader.h"
#include "Employee.h"
#include "Book.h"

Loan::Loan(int id, const shared_ptr<Reader>& reader, const shared_ptr<Book>& book,
    const shared_ptr<Employee>& employee, int loanDurationDays)
    : loanId(id), reader(reader), book(book), processedBy(employee),
    isReturned(false), lateFee(0.0) {
}

int Loan::calculateOverdueDays() const {
    if (isReturned || returnDate.empty()) return 0;

    int dueYear = stoi(dueDate.substr(0, 4));
    int dueMonth = stoi(dueDate.substr(5, 2));
    int returnYear = stoi(returnDate.substr(0, 4));
    int returnMonth = stoi(returnDate.substr(5, 2));

    if (returnYear > dueYear) return 365;
    if (returnYear == dueYear && returnMonth > dueMonth) return 30;
    return 0;
}

double Loan::calculateLateFee() const {
    int overdueDays = calculateOverdueDays();
    return overdueDays > 0 ? overdueDays * 10.0 : 0.0;
}

bool Loan::canBeRenewed() const {
    return !isReturned && calculateOverdueDays() == 0;
}

bool Loan::validateLoanDates() const {
    return !loanDate.empty() && !dueDate.empty() && dueDate > loanDate;
}

int Loan::getRemainingDays() const {
    if (isReturned) return 0;

    int dueYear = stoi(dueDate.substr(0, 4));
    int dueMonth = stoi(dueDate.substr(5, 2));
    return (dueYear - 2024) * 365 + (dueMonth - 1) * 30;
}

bool Loan::isOverdue() const {
    return calculateOverdueDays() > 0;
}

bool Loan::isLongTermLoan() const {
    int loanYear = stoi(loanDate.substr(0, 4));
    int dueYear = stoi(dueDate.substr(0, 4));
    return (dueYear - loanYear) >= 1;
}

void Loan::returnBook() {
    isReturned = true;
    lateFee = calculateLateFee();
}

void Loan::renewLoan(int additionalDays) {
    if (canBeRenewed()) {
        int dueYear = stoi(dueDate.substr(0, 4));
        int dueMonth = stoi(dueDate.substr(5, 2));
        dueMonth += additionalDays / 30;
        dueYear += dueMonth / 12;
        dueMonth = dueMonth % 12;

        dueDate = to_string(dueYear) + "-" +
            (dueMonth < 10 ? "0" : "") + to_string(dueMonth) + "-" +
            dueDate.substr(8, 2);
    }
}

void Loan::calculateAutoLateFee() {
    if (!isReturned) {
        lateFee = calculateLateFee();
    }
}

int Loan::getLoanId() const {
    return loanId;
}

string Loan::getLoanDate() const {
    return loanDate;
}

string Loan::getDueDate() const {
    return dueDate;
}

bool Loan::getIsReturned() const {
    return isReturned;
}

double Loan::getLateFee() const {
    return lateFee;
}

shared_ptr<Book> Loan::getBook() const {
    return book;
}

shared_ptr<Reader> Loan::getReader() const {
    return reader;
}