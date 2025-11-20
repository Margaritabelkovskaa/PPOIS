#include "ReadingRoomStaff.h"

ReadingRoomStaff::ReadingRoomStaff(int id, const std::string& name, const std::string& position,
    double salary, const std::shared_ptr<Department>& department,
    int maxReaders)
    : Employee(id, name, position, salary, department), maxReaders(maxReaders) {
}

bool ReadingRoomStaff::canProcessLoans() const {
    return false; // Персонал читального зала не может обрабатывать займы
}

std::string ReadingRoomStaff::getRole() const {
    return "Reading Room Staff";
}

bool ReadingRoomStaff::canAssistInReadingRoom() const {
    return true;
}

int ReadingRoomStaff::getMaxReaders() const {
    return maxReaders;
}

bool ReadingRoomStaff::isRoomFull(int currentReaders) const {
    return currentReaders >= maxReaders;
}