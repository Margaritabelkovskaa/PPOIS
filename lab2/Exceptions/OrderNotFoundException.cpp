#include "OrderNotFoundException.h"

OrderNotFoundException::OrderNotFoundException(int orderId)
    : TransportException("Order not found with ID: " + std::to_string(orderId)) {}
