#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <vector>
#include <memory>
#include <chrono>

using namespace std;

class Book; // Forward declaration

class Author {
private:
    string name;
    string biography;
    string birthDate;
    string nationality;
    vector<shared_ptr<Book>> books;

public:
    Author(const string& name, const string& birthDate,
        const string& nationality = "");

    // Уникальное поведение 4: Расчет возраста автора
    int calculateAge() const;

    // Уникальное поведение 5: Проверка продуктивности
    bool isProductive(int threshold = 10) const;

    void addBook(const shared_ptr<Book>& book);
    void setBiography(const string& bio);

    string getName() const;
    string getNationality() const;
    int getBooksCount() const;
};

#endif