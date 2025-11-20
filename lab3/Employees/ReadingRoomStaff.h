
#ifndef READINGROOMSTAFF_H
#define READINGROOMSTAFF_H

#include "Employee.h"

class ReadingRoomStaff : public Employee {
private:
    int maxReaders; // максимальное количество читателей для обслуживания

public:
    ReadingRoomStaff(int id, const std::string& name, const std::string& position,
        double salary, const std::shared_ptr<Department>& department,
        int maxReaders = 50);

    bool canProcessLoans() const override;
    std::string getRole() const override;

    bool canAssistInReadingRoom() const;
    int getMaxReaders() const;
    bool isRoomFull(int currentReaders) const;
};

#endif


