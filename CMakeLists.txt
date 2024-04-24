cmake_minimum_required(VERSION 3.22)
project(LeetCode_Debug)

set(CMAKE_CXX_STANDARD 20)

include_directories(common)

# add_executable(LeetCode_Debug main.cpp
#         common/leetcode.h
#         solutions.h)

# add_executable(test0204 test0204.cpp
#         helper.h)
add_executable(replaceSpaces 04/0418/replaceSpaces.cpp)
