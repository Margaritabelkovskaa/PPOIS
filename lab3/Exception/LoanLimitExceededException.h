#ifndef LOANLIMITEXCEEDEDEXCEPTION_H
#define LOANLIMITEXCEEDEDEXCEPTION_H

#include "LibraryException.h"

class LoanLimitExceededException : public LibraryException {
public:
    explicit LoanLimitExceededException(int limit);
};

#endif
