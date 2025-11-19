#include "Publisher.h"

Publisher::Publisher(const std::string& name, const std::string& address)
    : name(name), address(address) {
}

std::string Publisher::getName() const {
    return name;
}

std::string Publisher::getAddress() const {
    return address;
}

std::string Publisher::getContactInfo() const {
    return contactInfo;
}

void Publisher::updateContactInfo(const std::string& contact) {
    contactInfo = contact;
}