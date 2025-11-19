#ifndef GENRE_H
#define GENRE_H

#include <string>

class Genre {
private:
    std::string genreName;      // Название жанра
    bool isAgeRestricted;       // Возрастные ограничения 

public:
    Genre(const std::string& name, bool ageRestricted = false);

    std::string getGenreName() const;
    bool isRestricted() const;
    bool canBeBorrowedByStudent() const;
    bool requiresAdultVerification() const;
};

#endif