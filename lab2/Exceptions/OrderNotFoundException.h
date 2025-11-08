#ifndef ORDERNOTFOUNDEXCEPTION_H
#define ORDERNOTFOUNDEXCEPTION_H

#include "TransportException.h"

class OrderNotFoundException : public TransportException {
public:
    explicit OrderNotFoundException(int orderId);
};

#endif
