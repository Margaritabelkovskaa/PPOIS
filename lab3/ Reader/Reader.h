#ifndef READER_H
#define READER_H

#include <string>
#include <memory>

using namespace std;

class Reader {
private:
    int readerId;
    string name;
    string contactInfo;
    string readerType;
    int maxLoanLimit;

public:
    Reader(int id, const string& name, const string& contactInfo,
        const string& readerType = "standard");

    // Только базовые геттеры и сеттеры
    int getReaderId() const;
    string getName() const;
    string getContactInfo() const;
    string getReaderType() const;
    int getMaxLoanLimit() const;

    void setContactInfo(const string& contact);
    void upgradeToPremium();
    bool isValid() const;
};

#endif