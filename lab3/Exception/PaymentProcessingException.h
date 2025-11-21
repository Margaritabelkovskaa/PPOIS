#ifndef PAYMENTPROCESSINGEXCEPTION_H
#define PAYMENTPROCESSINGEXCEPTION_H

#include "LibraryException.h"
#include <string>

class PaymentProcessingException : public LibraryException {
public:
    explicit PaymentProcessingException(const std::string& details);
};

#endif
