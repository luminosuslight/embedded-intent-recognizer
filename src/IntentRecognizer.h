#ifndef INTENTRECOGNIZER_H
#define INTENTRECOGNIZER_H

#include <string>

#include "Intent.h"

/**
 * @brief The IntentRecognizer class sets up and stores all available intents.
 * It allows to find the best matching of those intents for a certain input phrase.
 */
class IntentRecognizer
{
public:
    IntentRecognizer();

    /**
     * @brief IntentRecognizer::getIntent returns the name of the best matching intent for an input phrase
     * @param phrase an input phrase, e.g. an utterance by a user
     * @return "Intent: <name of intent>"
     *
     * The best matching intent is found by comparing the suitability-score of all available intents.
     * If one intent matches using a short pattern and another matches using a longer pattern on
     * the same input phrase, the latter intent is chosen.
     */
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
