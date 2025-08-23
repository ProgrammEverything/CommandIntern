cmake_minimum_required(VERSION 3.13.0)
project(CommandIntern VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED on)
file(GLOB_RECURSE SOURCE "src/*.cpp")

add_executable(CommandIntern ${SOURCE})
target_include_directories(CommandIntern PRIVATE hdrs)

include(CTest)
enable_testing()

