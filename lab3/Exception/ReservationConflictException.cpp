#include "ReservationConflictException.h"

ReservationConflictException::ReservationConflictException(const std::string& title)
    : LibraryException("Reservation conflict for: " + title) {
}
