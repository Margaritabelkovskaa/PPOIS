#ifndef ARTICLE_H
#define ARTICLE_H

#include "LibraryItem.h"
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Article : public LibraryItem {
private:
    string journalName;
    string researchField;
    int publicationYear;
    vector<string> authors;

public:
    Article(const string& id, const string& title, const string& journal,
        const string& field, int year);

    void addAuthor(const string& author);

    string getJournalName() const;
    string getResearchField() const;
    int getPublicationYear() const;
    vector<string> getAuthors() const;

    bool isRecent() const;
};

#endif