#ifndef INTENTRECOGNIZER_H
#define INTENTRECOGNIZER_H

#include <string>

#include "Intent.h"

class IntentRecognizer
{
public:
    IntentRecognizer();

    std::string getIntent(const std::string &phrase) const;

private:
    /**
     * @brief IntentRecognizer::setupIntents creates the intents that this system should understand
     */
    void setupIntents();

protected:
    std::vector<Intent> m_intents;
};

#endif // INTENTRECOGNIZER_H
