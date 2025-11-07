#include "Reader.h"
#include "Loan.h"
#include "Reservation.h"

Reader::Reader(int id, const std::string& name, const std::string& email,
               const std::string& type)
    : id(id), name(name), email(email), type(type), fines(0) {
    
    if (type == "premium") {
        maxBooks = 10;
    } else if (type == "vip") {
        maxBooks = 20;
    } else {
        maxBooks = 5;
    }
}

void Reader::upgradeToPremium() {
    type = "premium";
    maxBooks = 10;
}

bool Reader::canBorrow() const {
    return loans.size() < maxBooks;
}

void Reader::addLoan(const std::shared_ptr<Loan>& loan) {
    if (canBorrow()) {
        loans.push_back(loan);
    }
}

void Reader::addReservation(const std::shared_ptr<Reservation>& reservation) {
    if (reservations.size() < 3) {
        reservations.push_back(reservation);
    }
}
