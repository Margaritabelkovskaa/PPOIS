#include "AccessDeniedException.h"

AccessDeniedException::AccessDeniedException(const std::string& role)
    : LibraryException("Access denied for role: " + role) {
}
