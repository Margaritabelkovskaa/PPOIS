#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <string>

class Publisher {
private:
    std::string name;        // Название издательства
    std::string address;     // Адрес
    std::string contactInfo; // Контакты

public:
    Publisher(const std::string& name, const std::string& address);

    std::string getName() const;
    std::string getAddress() const;
    std::string getContactInfo() const;

    void updateContactInfo(const std::string& contact);
};

#endif