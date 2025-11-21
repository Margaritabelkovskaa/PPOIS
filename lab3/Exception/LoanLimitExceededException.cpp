#include "LoanLimitExceededException.h"

LoanLimitExceededException::LoanLimitExceededException(int limit)
    : LibraryException("Loan limit exceeded: " + std::to_string(limit)) {
}
