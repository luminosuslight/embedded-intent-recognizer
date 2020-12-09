#include "IntentRecognizer.h"

#include <iostream>

IntentRecognizer::IntentRecognizer()
{
    setupIntents();
}

std::string IntentRecognizer::getIntent(const std::string &phrase) const
{
    double bestScore = 0.0;
    std::optional<Intent> bestIntent;
    for (const auto &intent: m_intents) {
        const double score = intent.getScore(phrase);
        if (score > bestScore) {
            bestScore = score;
            bestIntent = intent;
        }
    }
    if (bestIntent) {
        const auto attributes = bestIntent->getAttributes(phrase);
        for (const auto &attribute: attributes) {
            std::cout << attribute.first << ": " << attribute.second << std::endl;
        }
        return "Intent: " + bestIntent->getName();
    }
    return "Intent: unknown";
}

void IntentRecognizer::setupIntents()
{
    Intent weather("Get Weather", {
                       "weather",
                       "weather <text> today"
                   });
    m_intents.push_back(weather);

    Intent weatherCity("Get Weather City", {
                           "weather <text> in <city:text> today",
                           "weather <text> in <city:text>",
                           "will it rain in <city:text>"
                       });
    m_intents.push_back(weatherCity);

    Intent calendar("Check calendar", {
                        "am I free <text>",
                        "appointment"
                    });
    m_intents.push_back(calendar);

    Intent fact("Get Fact", {
                    "fact",
                    "tell <text> fact"
                });
    m_intents.push_back(fact);
}
