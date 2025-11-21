#include "InsufficientFundsException.h"

InsufficientFundsException::InsufficientFundsException(double amount)
    : LibraryException("Insufficient funds for: " + std::to_string(amount)) {
}
