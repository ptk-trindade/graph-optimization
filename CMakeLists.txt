cmake_minimum_required(VERSION 3.10)
project(GraphOptimization)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(YourExecutableName
    src/main.cpp
    src/Solution.cpp
    src/Problem.cpp
    src/SolutionStep.cpp
)
