#ifndef TRANSPORTEXCEPTION_H
#define TRANSPORTEXCEPTION_H

#include <stdexcept>
#include <string>

class TransportException : public std::exception {
private:
    std::string message;
public:
    explicit TransportException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

#endif
