find_package(Catch2 REQUIRED)

include_directories(${embedded_intent_recognizer_SOURCE_DIR}/src)

add_executable(embedded_intent_recognizer_test test.cpp)

target_link_libraries(embedded_intent_recognizer_test
    intent_recognizer_lib
    Catch2::Catch2WithMain)

add_test(NAME BasicTest COMMAND embedded_intent_recognizer_test)
