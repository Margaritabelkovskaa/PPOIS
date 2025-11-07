#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include <memory>

class Loan;
class Reservation;

class Reader {
private:
    int id;
    std::string name;
    std::string email;
    std::string type;
    int maxBooks;
    double fines;
    
    std::vector<std::shared_ptr<Loan>> loans;
    std::vector<std::shared_ptr<Reservation>> reservations;

public:
    Reader(int id, const std::string& name, const std::string& email, 
           const std::string& type = "standard");
    
    // Основные методы
    void upgradeToPremium();
    bool canBorrow() const;
    void addLoan(const std::shared_ptr<Loan>& loan);
    void addReservation(const std::shared_ptr<Reservation>& reservation);
    

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
    std::string getType() const { return type; }
    int getMaxBooks() const { return maxBooks; }
    int getLoansCount() const { return loans.size(); }
    double getFines() const { return fines; }

    void setEmail(const std::string& newEmail) { email = newEmail; }
    void setFines(double amount) { fines = amount; }
};

#endif
