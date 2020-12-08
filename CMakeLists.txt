cmake_minimum_required(VERSION 3.5)

project(embedded_intent_recognizer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(embedded_intent_recognizer src/main.cpp)
