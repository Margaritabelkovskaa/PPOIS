#ifndef LOAN_H
#define LOAN_H

#include <string>
#include <memory>

using namespace std;

class Reader;
class Book;
class Employee;

class Loan {
private:
    int loanId;
    shared_ptr<Reader> reader;
    shared_ptr<Book> book;
    shared_ptr<Employee> processedBy;
    string loanDate;
    string dueDate;
    string returnDate;
    bool isReturned;
    double lateFee;

public:
    Loan(int id, const shared_ptr<Reader>& reader, const shared_ptr<Book>& book,
        const shared_ptr<Employee>& employee, int loanDurationDays = 14);

    int calculateOverdueDays() const;
    double calculateLateFee() const;
    bool canBeRenewed() const;
    bool validateLoanDates() const;
    int getRemainingDays() const;
    bool isOverdue() const;
    bool isLongTermLoan() const;

    void returnBook();
    void renewLoan(int additionalDays);
    void calculateAutoLateFee();

    int getLoanId() const;
    string getLoanDate() const;
    string getDueDate() const;
    bool getIsReturned() const;
    double getLateFee() const;
    shared_ptr<Book> getBook() const;
    shared_ptr<Reader> getReader() const;
};

#endif