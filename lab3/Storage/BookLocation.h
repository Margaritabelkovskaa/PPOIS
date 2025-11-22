#ifndef BOOKLOCATION_H
#define BOOKLOCATION_H

#include <string>
using namespace std;

class BookLocation {
private:
    string section;
    string rack;
    string shelf;
    string position;
    string locationCode;  
    bool isActive;        

public:
    BookLocation(const string& section, const string& rack, const string& shelf, const string& position);

    string getFullLocation() const;
    bool isValid() const;

    string getSection() const;
    string getRack() const;
    string getShelf() const;
    string getPosition() const;
    string getLocationCode() const;
    bool getIsActive() const;
    void setIsActive(bool active);
};

#endif
