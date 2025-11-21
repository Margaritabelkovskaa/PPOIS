#ifndef RESERVATIONCONFLICTEXCEPTION_H
#define RESERVATIONCONFLICTEXCEPTION_H

#include "LibraryException.h"
#include <string>

class ReservationConflictException : public LibraryException {
public:
    explicit ReservationConflictException(const std::string& title);
};

#endif
