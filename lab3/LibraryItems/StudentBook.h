#ifndef STUDENTBOOK_H
#define STUDENTBOOK_H

#include "Book.h"
#include <string>
#include <memory>

class StudentBook : public Book {
private:
    std::string subject;
    std::string educationalLevel;
    bool hasAnswers;

public:
    StudentBook(const std::string& isbn, const std::string& title,
        const std::shared_ptr<Author>& author, int publicationYear,
        const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
        const std::shared_ptr<Language>& bookLanguage,
        const std::string& subject, const std::string& educationalLevel,
        bool hasAnswers = false, double cost = 0.0);

    bool canBeBorrowed() const override;
    int getLoanDuration() const override;

    bool isForSchool() const;
    bool isForUniversity() const;
    bool canBeBorrowedByStudent(bool isStudent) const;

    std::string getSubject() const;
    std::string getEducationalLevel() const;
    bool getHasAnswers() const;
};

#endif