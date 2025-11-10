cmake_minimum_required(VERSION 4.0)
project(ProcessScheduler)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Process.cpp Scheduler.cpp)

add_executable(process_scheduler ${SOURCE_FILES})