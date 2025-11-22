#include "BookLocation.h"

BookLocation::BookLocation(const string& section, const string& rack, const string& shelf, const string& position)
    : section(section), rack(rack), shelf(shelf), position(position), 
      locationCode(section + "_" + rack + "_" + shelf + "_" + position),
      isActive(true) {
}

string BookLocation::getFullLocation() const {
    return section + " -> " + rack + " -> " + shelf + " -> " + position;
}

bool BookLocation::isValid() const {
    return !section.empty() && !rack.empty() && !shelf.empty() && !position.empty() && isActive;
}

string BookLocation::getSection() const { return section; }
string BookLocation::getRack() const { return rack; }
string BookLocation::getShelf() const { return shelf; }
string BookLocation::getPosition() const { return position; }
string BookLocation::getLocationCode() const { return locationCode; }
bool BookLocation::getIsActive() const { return isActive; }
void BookLocation::setIsActive(bool active) { isActive = active; }
