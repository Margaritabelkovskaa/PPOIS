#include "DatabaseConnectionException.h"

DatabaseConnectionException::DatabaseConnectionException()
    : LibraryException("Database connection failed") {
}
