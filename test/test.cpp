#include <catch2/catch_all.hpp>

#include "IntentRecognizer.h"

TEST_CASE( "class can be constructed and deconstructed", "[basic]" ) {
    REQUIRE_NOTHROW ([]() {
        auto* instance = new IntentRecognizer();
        delete instance;
    });
}

TEST_CASE( "check basic intent recognition", "[intents]" ) {
    IntentRecognizer recognizer;

    REQUIRE( recognizer.getIntent("What is the weather like today?") == "Intent: Get Weather" );
    REQUIRE( recognizer.getIntent("What is the weather like in Paris today?") == "Intent: Get Weather City" );
    REQUIRE( recognizer.getIntent("What is the weather like in New York today?") == "Intent: Get Weather City" );
    REQUIRE( recognizer.getIntent("Am I free at 13:00 PM tomorrow?") == "Intent: Check calendar" );
    REQUIRE( recognizer.getIntent("Tell me an interesting fact.") == "Intent: Get Fact" );
}

TEST_CASE( "check 'very advanced' intent recognition", "[intents]" ) {
    IntentRecognizer recognizer;

    REQUIRE( recognizer.getIntent("Do I have an appointment at 13:00pm tomorrow?") == "Intent: Check calendar" );
    REQUIRE( recognizer.getIntent("Will it rain tomorrow in Paris?") == "Intent: Get Weather City" );
}
