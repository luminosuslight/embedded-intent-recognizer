add_library(intent_recognizer_lib
    IntentRecognizer.cpp IntentRecognizer.h
    Intent.cpp Intent.h)

add_executable(embedded_intent_recognizer_app main.cpp)

target_link_libraries(embedded_intent_recognizer_app intent_recognizer_lib)
