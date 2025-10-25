#include "DrivingLicense.h"

DrivingLicense::DrivingLicense(const std::string& number, const std::string& categories,
    const std::string& issue, const std::string& expiry)
    : number(number), categories(categories), issueDate(issue), expiryDate(expiry) {
}

bool DrivingLicense::isValid() const {
    return true; // Упрощенная проверка
}

bool DrivingLicense::canDriveCategory(const std::string& category) const {
    return categories.find(category) != std::string::npos;
}