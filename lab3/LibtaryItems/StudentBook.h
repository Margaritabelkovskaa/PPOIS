#ifndef STUDENTBOOK_H
#define STUDENTBOOK_H

#include "Book.h"

class StudentBook : public Book {
private:
    string subject;
    string courseLevel; // "bachelor", "master", "phd"
    int semester;
    bool hasPracticeTasks;

public:
    StudentBook(const string& isbn, const string& title, const shared_ptr<Author>& author,
        int publicationYear, const shared_ptr<Genre>& genre,
        const shared_ptr<Publisher>& publisher, const string& subject,
        const string& courseLevel = "bachelor", int semester = 1);

    string getSubject() const;
    string getCourseLevel() const;
    int getSemester() const;
    bool getHasPracticeTasks() const;

    bool isForBachelor() const;
    bool isForMaster() const;
    bool isForPhD() const;
};

#endif