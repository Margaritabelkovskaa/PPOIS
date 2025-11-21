#ifndef SYSTEMCONFIGURATIONEXCEPTION_H
#define SYSTEMCONFIGURATIONEXCEPTION_H

#include "LibraryException.h"
#include <string>

class SystemConfigurationException : public LibraryException {
public:
    explicit SystemConfigurationException(const std::string& config);
};

#endif
