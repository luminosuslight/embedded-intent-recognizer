#include "IntentRecognizer.h"

IntentRecognizer::IntentRecognizer()
{

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
