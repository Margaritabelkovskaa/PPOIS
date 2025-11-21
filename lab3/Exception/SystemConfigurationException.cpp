#include "SystemConfigurationException.h"

SystemConfigurationException::SystemConfigurationException(const std::string& config)
    : LibraryException("Invalid configuration: " + config) {
}
