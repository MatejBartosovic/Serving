cmake_minimum_required(VERSION 3.16)

project(Serving)
set(CMAKE_CXX_STANDARD 20)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

add_subdirectory(test)

add_library(${PROJECT_NAME}
        src/Command.cpp
        src/ServeCommandsMode.cpp
        src/ServeModesMode.cpp
        src/CommonCommands.cpp
        src/Mode.cpp
        src/Exception.cpp
        src/ServingPolicy.cpp
        src/SplitString.cpp
        src/NullStream.cpp)

target_link_libraries(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
        )

add_executable(${PROJECT_NAME}_test_main
        src/main.cpp)

target_link_libraries(${PROJECT_NAME}_test_main
        PRIVATE
        ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME} DESTINATION lib
        )
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include DESTINATION .)
install(EXPORT ${PROJECT_NAME}
        DESTINATION
        lib/cmake/${PROJECT_NAME}
        NAMESPACE
        ${PROJECT_NAME}::
        FILE
        ${PROJECT_NAME}Config.cmake
        )
