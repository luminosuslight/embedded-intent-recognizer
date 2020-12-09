#include <iostream>

#include "IntentRecognizer.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Usage: embedded_intent_recognizer_app \"input phrase\"" << std::endl;
        return 0;
    }

    IntentRecognizer recognizer;

    const auto intent = recognizer.getIntent(argv[1]);
    std::cout << intent << std::endl;

    return 0;
}
