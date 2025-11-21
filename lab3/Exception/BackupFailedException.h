#ifndef BACKUPFAILEDEXCEPTION_H
#define BACKUPFAILEDEXCEPTION_H

#include "LibraryException.h"
#include <string>

class BackupFailedException : public LibraryException {
public:
    explicit BackupFailedException(const std::string& reason);
};

#endif
