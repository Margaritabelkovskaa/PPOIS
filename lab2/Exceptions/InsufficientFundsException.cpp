#include "InsufficientFundsException.h"

InsufficientFundsException::InsufficientFundsException()
    : TransportException("Insufficient funds for transaction") {}
