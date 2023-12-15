cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)

# Set the project name
project(assessment)

# Set the source files for the main executable
set(SOURCES
    main.cpp
)

# Build the main executable
add_executable(main ${SOURCES})

# If BUILD_TESTS option is ON, build the tests
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    # Set the source files for the test executable
    set(TEST_SOURCES
        unittests.cpp
    )
    
    # Locate GTest
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    
    # Build the test executable
    add_executable(runTests ${TEST_SOURCES})
    target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
endif()
