cmake_minimum_required(VERSION 3.4)
project(C++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory("Person")
add_subdirectory("sqlite3")
include_directories("Person")
include_directories("sqlite3")

set(SOURCE_FILES sqlite3/test.cpp person.cpp system.cpp)
add_executable(C++ ${SOURCE_FILES} Person sqlite3)

target_link_libraries(C++ Person sqlite3)