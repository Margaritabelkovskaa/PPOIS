
#include "MaterialTypeSearch.h"

MaterialTypeSearch::MaterialTypeSearch(const shared_ptr<Catalog>& catalog)
    : SearchEngine(catalog) {
}

vector<shared_ptr<Book>> MaterialTypeSearch::search(const string& query) const {
    vector<shared_ptr<Book>> result;
    if (!catalog) return result;

    // Поиск по типу материала на основе запроса
    if (query == "ebook" || query == "e-book") {
        auto ebooks = searchEBooks();
        result.insert(result.end(), ebooks.begin(), ebooks.end());
    }
    else if (query == "audiobook" || query == "audio") {
        auto audiobooks = searchAudiobooks();
        result.insert(result.end(), audiobooks.begin(), audiobooks.end());
    }
    else if (query == "student" || query == "textbook") {
        auto studentBooks = searchStudentBooks();
        result.insert(result.end(), studentBooks.begin(), studentBooks.end());
    }

    return result;
}

string MaterialTypeSearch::getSearchType() const {
    return "Material Type Search";
}

vector<shared_ptr<EBook>> MaterialTypeSearch::searchEBooks() const {
    vector<shared_ptr<EBook>> result;
    if (!catalog) return result;

    auto allBooks = catalog->findBooksByAuthor(""); // Заменить на реальный метод

    for (const auto& book : allBooks) {
        if (auto ebook = dynamic_pointer_cast<EBook>(book)) {
            result.push_back(ebook);
        }
    }

    return result;
}

vector<shared_ptr<Audiobook>> MaterialTypeSearch::searchAudiobooks() const {
    vector<shared_ptr<Audiobook>> result;
    if (!catalog) return result;

    auto allBooks = catalog->findBooksByAuthor(""); // Заменить на реальный метод

    for (const auto& book : allBooks) {
        if (auto audiobook = dynamic_pointer_cast<Audiobook>(book)) {
            result.push_back(audiobook);
        }
    }

    return result;
}

vector<shared_ptr<StudentBook>> MaterialTypeSearch::searchStudentBooks() const {
    vector<shared_ptr<StudentBook>> result;
    if (!catalog) return result;

    auto allBooks = catalog->findBooksByAuthor(""); // Заменить на реальный метод

    for (const auto& book : allBooks) {
        if (auto studentBook = dynamic_pointer_cast<StudentBook>(book)) {
            result.push_back(studentBook);
        }
    }

    return result;
}

// Шаблонный метод для поиска по любому типу
template<typename T>
vector<shared_ptr<T>> MaterialTypeSearch::searchByType() const {
    vector<shared_ptr<T>> result;
    if (!catalog) return result;

    auto allBooks = catalog->findBooksByAuthor(""); // Заменить на реальный метод

    for (const auto& book : allBooks) {
        if (auto typedBook = dynamic_pointer_cast<T>(book)) {
            result.push_back(typedBook);
        }
    }

    return result;
}