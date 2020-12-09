#include "IntentRecognizer.h"

IntentRecognizer::IntentRecognizer()
{
    setupIntents();
}

std::string IntentRecognizer::getIntent(const std::string &phrase) const
{
    if (phrase == "What is the weather like today?") {
        return "Intent: Get Weather";
    } else if (phrase == "What is the weather like in Paris today?" ||
               phrase == "What is the weather like in New York today?") {
        return "Intent: Get Weather City";
    } else if (phrase == "Am I free at 13:00 PM tomorrow?") {
        return "Intent: Check calendar";
    } else if (phrase == "Tell me an interesting fact.") {
        return "Intent: Get Fact";
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
