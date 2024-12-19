# This is the minimum required version of CMake to build this project.
cmake_minimum_required(VERSION 3.10)

# This command sets the name of the project and specifies the languages used.
project(ATM C CXX)

# This sets the C++ standard to be used by the project to C++20.
set(CMAKE_CXX_STANDARD 11)

# This sets the working directory to the current source directory.
set(WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# This command collects all .cpp files in the "sources" directory and stores them in the SOURCES variable.
file(GLOB SOURCES "sources/*.cpp")

# This command includes the "headers" directory so that the compiler can find header files located there.
include_directories("${WORKING_DIRECTORY}/headers")

# This command creates an executable with the name of the project (RPS) and includes the main.cpp file and all source files collected in the SOURCES variable.
add_executable(${PROJECT_NAME}
main.cpp
${SOURCES}
)