#include "Article.h"

Article::Article(const string& id, const string& title, const string& journal,
    const string& field, int year, double cost)
    : LibraryItem(id, title, cost), journalName(journal),
    researchField(field), publicationYear(year) {
}

void Article::addAuthor(const string& author) {
    authors.push_back(author);
}

string Article::getJournalName() const {
    return journalName;
}

string Article::getResearchField() const {
    return researchField;
}

int Article::getPublicationYear() const {
    return publicationYear;
}

vector<string> Article::getAuthors() const {
    return authors;
}

bool Article::isRecent() const {
    return publicationYear >= 2020;
}

bool Article::canBeBorrowed() const  {
    return isAvailable;
}

int Article::getLoanDuration() const  {
    return 14;
}