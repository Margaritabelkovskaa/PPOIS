#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include <memory>

using namespace std;

class Loan;
class Reservation;

class Reader {
private:
    int readerId;
    string name;
    string contactInfo;
    string readerType;
    int maxLoanLimit;
    double totalFines;
    
    // Ассоциации
    vector<shared_ptr<Loan>> currentLoans;
    vector<shared_ptr<Loan>> loanHistory;
    vector<shared_ptr<Reservation>> activeReservations;
    vector<shared_ptr<Reservation>> reservationHistory;

public:
    Reader(int id, const string& name, const string& contactInfo, 
           const string& readerType = "standard");
    
    // Уникальные поведения
    void upgradeToPremium();
    bool isValid() const;
    bool canBorrowMoreBooks() const;
    bool canMakeReservation() const;
    int getActiveLoansCount() const;
    int getActiveReservationsCount() const;
    
    // Управление ассоциациями
    void addLoan(const shared_ptr<Loan>& loan);
    void addReservation(const shared_ptr<Reservation>& reservation);
    void returnLoan(const shared_ptr<Loan>& loan);
    void cancelReservation(const shared_ptr<Reservation>& reservation);
    
    // Геттеры
    int getReaderId() const;
    string getName() const;
    string getContactInfo() const;
    string getReaderType() const;
    int getMaxLoanLimit() const;
    double getTotalFines() const;
    
    // Сеттеры
    void setContactInfo(const string& contact);
    void setTotalFines(double fines);
};

#endif
