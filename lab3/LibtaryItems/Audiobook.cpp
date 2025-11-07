#include "Audiobook.h"

Audiobook::Audiobook(const string& isbn, const string& title, const shared_ptr<Author>& author,
    int publicationYear, const shared_ptr<Genre>& genre,
    const shared_ptr<Publisher>& publisher, double duration,
    const string& format, const string& narrator)
    : Book(isbn, title, author, publicationYear, genre, publisher),
    duration(duration), format(format), narrator(narrator), bitrate(128) {
}

double Audiobook::calculateListeningTime(double speed) const {
    return speed > 0 ? duration / speed : duration;
}

bool Audiobook::isHighQuality() const {
    return bitrate >= 192;
}

bool Audiobook::validateAudioFormat() const {
    return format == "MP3" || format == "AAC" || format == "FLAC";
}

double Audiobook::calculateReplacementCost() const {
    return 400.0;
}

bool Audiobook::isLongAudiobook() const {
    return duration > 600.0;
}

string Audiobook::getDurationFormatted() const {
    int hours = static_cast<int>(duration) / 60;
    int minutes = static_cast<int>(duration) % 60;
    return to_string(hours) + "h " + to_string(minutes) + "m";
}

double Audiobook::getDuration() const {
    return duration;
}

string Audiobook::getNarrator() const {
    return narrator;
}

int Audiobook::getBitrate() const {
    return bitrate;
}