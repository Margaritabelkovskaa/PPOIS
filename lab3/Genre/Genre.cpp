#include "Genre.h"

Genre::Genre(const std::string& name, bool ageRestricted)
    : genreName(name), isAgeRestricted(ageRestricted) {
}

std::string Genre::getGenreName() const {
    return genreName;
}

bool Genre::isRestricted() const {
    return isAgeRestricted;
}

bool Genre::canBeBorrowedByStudent() const {
    return !isAgeRestricted;
}

bool Genre::requiresAdultVerification() const {
    return isAgeRestricted;
}