#include "BackupFailedException.h"

BackupFailedException::BackupFailedException(const std::string& reason)
    : LibraryException("Backup failed: " + reason) {
}
