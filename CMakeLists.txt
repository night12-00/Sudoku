## Dominic-github (https://github.com/Dominic-github)

# This is a minimal CMakeLists file which includes the Yoctopuce C++ lib.
cmake_minimum_required(VERSION 3.16)

project (Sudoku)

include_directories(include)
include_directories(include/lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (WIN32)
file(GLOB SOURCES 
  "src/*.cpp"
)
else()
file(GLOB SOURCES 
  "src/*.cpp"
  "src/lib/*cpp"  
)
endif(WIN32)


# Adds the executable called "demo" that is built from the source files "main.cpp".
add_executable(main ${SOURCES})

if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
  enable_testing()
  message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
  add_subdirectory(test)
endif()

