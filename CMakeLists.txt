cmake_minimum_required(VERSION 3.10)

project(String LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CPP_COMPILER g++)

# Testing module
add_subdirectory(thirdparty/catch2)

# String library
enable_testing()
add_subdirectory(string)

# Examples
add_subdirectory(examples)

