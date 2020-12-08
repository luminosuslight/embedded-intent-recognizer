#include <catch2/catch_all.hpp>

#include "IntentRecognizer.h"

TEST_CASE( "class can be constructed and deconstructed", "[basic]" ) {
    REQUIRE_NOTHROW ([]() {
        auto* instance = new IntentRecognizer();
        delete instance;
    });
}
