#include "PaymentProcessingException.h"

PaymentProcessingException::PaymentProcessingException(const std::string& details)
    : LibraryException("Payment failed: " + details) {
}
