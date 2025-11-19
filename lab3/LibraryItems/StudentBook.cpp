#include "StudentBook.h"

StudentBook::StudentBook(const std::string& isbn, const std::string& title,
    const std::shared_ptr<Author>& author, int publicationYear,
    const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
    const std::shared_ptr<Language>& bookLanguage,
    const std::string& subject, const std::string& educationalLevel,
    bool hasAnswers, double cost)
    : Book(isbn, title, author, publicationYear, genre, publisher, bookLanguage, cost),
    subject(subject), educationalLevel(educationalLevel), hasAnswers(hasAnswers) {
}

bool StudentBook::canBeBorrowed() const {
    return isAvailable;
}

int StudentBook::getLoanDuration() const {
    return 180;
}

bool StudentBook::isForSchool() const {
    return educationalLevel == "school" || educationalLevel == "школьный";
}

bool StudentBook::isForUniversity() const {
    return educationalLevel == "university" || educationalLevel == "вузовский";
}

bool StudentBook::canBeBorrowedByStudent(bool isStudent) const {
    return isStudent;
}

std::string StudentBook::getSubject() const {
    return subject;
}

std::string StudentBook::getEducationalLevel() const {
    return educationalLevel;
}

bool StudentBook::getHasAnswers() const {
    return hasAnswers;
}