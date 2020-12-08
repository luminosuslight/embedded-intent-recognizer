#ifndef INTENTRECOGNIZER_H
#define INTENTRECOGNIZER_H

#include <string>

class IntentRecognizer
{
public:
    IntentRecognizer();

    std::string getIntent(const std::string &phrase) const;
};

#endif // INTENTRECOGNIZER_H
