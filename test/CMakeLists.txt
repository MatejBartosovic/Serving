find_package(Threads REQUIRED)
find_package(GTest)
if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG        release-1.10.0
    )
    FetchContent_MakeAvailable(googletest)
endif()

add_executable(${PROJECT_NAME}_unittest
        main.cpp
        )

target_link_libraries(${PROJECT_NAME}_unittest
        PRIVATE ${PROJECT_NAME} gtest gtest_main Threads::Threads )

add_test(${PROJECT_NAME}_unittest ${PROJECT_NAME}_unittest)