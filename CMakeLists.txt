cmake_minimum_required(VERSION 3.10)
project(ATM)

set(CMAKE_CXX_STANDARD 11)

# This sets the working directory to the current source directory.
set(WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# This command collects all .cpp files in the "sources" directory and stores them in the SOURCES variable.
file(GLOB SOURCES "sources/*.cpp")

# This command includes the "headers" directory so that the compiler can find header files located there.
include_directories("${WORKING_DIRECTORY}/headers")

# Include the sqlite directory
include_directories("${WORKING_DIRECTORY}/sqlite")

# Add sqlite source files, excluding shell.c
file(GLOB SQLITE_SOURCES "sqlite/*.c" "sqlite/*.cpp")
list(REMOVE_ITEM SQLITE_SOURCES "${WORKING_DIRECTORY}/sqlite/shell.c")

# This command creates an executable with the name of the project (ATM) and includes the main.cpp file and all source files collected in the SOURCES variable.
add_executable(${PROJECT_NAME}
    main.cpp
    ${SOURCES}
    ${SQLITE_SOURCES}
)