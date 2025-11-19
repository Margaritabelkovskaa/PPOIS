#include "Audiobook.h"

Audiobook::Audiobook(const std::string& isbn, const std::string& title,
    const std::shared_ptr<Author>& author, int publicationYear,
    const std::shared_ptr<Genre>& genre, const std::shared_ptr<Publisher>& publisher,
    const std::shared_ptr<Language>& bookLanguage,
    double duration, const std::string& format, const std::string& narrator, double cost)
    : Book(isbn, title, author, publicationYear, genre, publisher, bookLanguage, cost),
    duration(duration), format(format), narrator(narrator) {
}

bool Audiobook::canBeBorrowed() const {
    return isAvailable && isSupportedFormat();
}

int Audiobook::getLoanDuration() const {
    return 21;
}

bool Audiobook::isLongAudiobook() const {
    return duration > 600;
}

bool Audiobook::isSupportedFormat() const {
    return format == "MP3" || format == "AAC" || format == "FLAC";
}

std::string Audiobook::getDurationFormatted() const {
    int hours = static_cast<int>(duration) / 60;
    int minutes = static_cast<int>(duration) % 60;
    return std::to_string(hours) + "h " + std::to_string(minutes) + "m";
}

double Audiobook::getDuration() const {
    return duration;
}

std::string Audiobook::getFormat() const {
    return format;
}

std::string Audiobook::getNarrator() const {
    return narrator;
}