cmake_minimum_required(VERSION 3.30)
project(HappyNumber)
project(HappyNumber_test)

set(CMAKE_CXX_STANDARD 17)

# Подключаем Google Test через FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(HappyNumber main.cpp
        HappyNumber.cpp
        HappyNumber.h
)

add_executable(HappyNumber_test
        HappyNumber.cpp
        HappyNumber.h
        gtest.cpp
)

target_link_libraries(HappyNumber_test GTest::gtest_main)

# Автоматически добавляем тесты
include(GoogleTest)
gtest_discover_tests(HappyNumber_test)