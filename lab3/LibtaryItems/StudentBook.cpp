#include "StudentBook.h"

StudentBook::StudentBook(const string& isbn, const string& title, const shared_ptr<Author>& author,
    int publicationYear, const shared_ptr<Genre>& genre,
    const shared_ptr<Publisher>& publisher, const string& subject,
    const string& courseLevel, int semester)
    : Book(isbn, title, author, publicationYear, genre, publisher),
    subject(subject), courseLevel(courseLevel), semester(semester),
    hasPracticeTasks(true) {
}

string StudentBook::getSubject() const {
    return subject;
}

string StudentBook::getCourseLevel() const {
    return courseLevel;
}

int StudentBook::getSemester() const {
    return semester;
}

bool StudentBook::getHasPracticeTasks() const {
    return hasPracticeTasks;
}

bool StudentBook::isForBachelor() const {
    return courseLevel == "bachelor";
}

bool StudentBook::isForMaster() const {
    return courseLevel == "master";
}

bool StudentBook::isForPhD() const {
    return courseLevel == "phd";
}

