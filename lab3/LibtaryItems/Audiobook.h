#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Book.h"

using namespace std;

class Audiobook : public Book {
private:
    double duration;
    string format;
    string narrator;
    int bitrate;

public:
    Audiobook(const string& isbn, const string& title, const shared_ptr<Author>& author,
        int publicationYear, const shared_ptr<Genre>& genre,
        const shared_ptr<Publisher>& publisher, double duration,
        const string& format, const string& narrator);

    double calculateListeningTime(double speed) const;
    bool isHighQuality() const;
    bool validateAudioFormat() const;
    double calculateReplacementCost() const override;
    bool isLongAudiobook() const;
    string getDurationFormatted() const;

    double getDuration() const;
    string getNarrator() const;
    int getBitrate() const;
};

#endif
