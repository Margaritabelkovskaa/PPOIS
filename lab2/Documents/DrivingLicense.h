
#ifndef DRIVINGLICENSE_H
#define DRIVINGLICENSE_H

#include <string>

class DrivingLicense {
private:
    std::string number;
    std::string categories;
    std::string issueDate;
    std::string expiryDate;

public:
    DrivingLicense(const std::string& number, const std::string& categories,
        const std::string& issue, const std::string& expiry);

    bool isValid() const;
    bool canDriveCategory(const std::string& category) const;

    std::string getNumber() const { return number; }
    std::string getCategories() const { return categories; }
};

#endif