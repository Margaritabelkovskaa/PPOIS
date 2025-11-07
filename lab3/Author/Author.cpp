#include "Author.h"
#include <iostream>
#include <chrono>

using namespace std;

Author::Author(const string& name, const string& birthDate,
    const string& nationality)
    : name(name), birthDate(birthDate), nationality(nationality) {
}

int Author::calculateAge() const {
    // Упрощенный расчет возраста
    if (birthDate.length() >= 4) {
        int birthYear = stoi(birthDate.substr(birthDate.length() - 4));

        // Получаем текущий год с помощью chrono
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);

        // Безопасное преобразование времени без localtime
        tm time_info;
        localtime_s(&time_info, &now_time);  // Для Windows
        // Или используйте: gmtime_r(&now_time, &time_info); // Для Linux

        int currentYear = time_info.tm_year + 1900;
        return currentYear - birthYear;
    }
    return 0;
}

bool Author::isProductive(int threshold) const {
    return books.size() >= threshold;
}

void Author::addBook(const shared_ptr<Book>& book) {
    books.push_back(book);
}

void Author::setBiography(const string& bio) {
    biography = bio;
}

string Author::getName() const {
    return name;
}

string Author::getNationality() const {
    return nationality;
}

int Author::getBooksCount() const {
    return books.size();
}