#include "ReadingRoomStaff.h"

ReadingRoomStaff::ReadingRoomStaff(int id, const string& name, const string& position,
    double salary, const shared_ptr<Department>& department)
    : Employee(id, name, position, salary, department) {
}

bool ReadingRoomStaff::canAssistReaders() const {
    return true;
}

string ReadingRoomStaff::getReadingRoomInfo() const {
    return "Reading Room Staff: " + getName();
}
