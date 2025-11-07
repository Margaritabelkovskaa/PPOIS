#ifndef READINGROOMSTAFF_H
#define READINGROOMSTAFF_H

#include "Employee.h"

class ReadingRoomStaff : public Employee {
public:
    ReadingRoomStaff(int id, const string& name, const string& position,
        double salary, const shared_ptr<Department>& department);

    bool canAssistReaders() const;
    string getReadingRoomInfo() const;
};
#endif


