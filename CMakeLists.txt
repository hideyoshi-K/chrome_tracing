cmake_minimum_required(VERSION 3.5)
project(chrome_tracing)
set(CMAKE_CXX_FLAGS "-Wall -std=c++14")

add_executable(main src/main.cpp)

## Thread
# find_package(Threads REQUIRED)
# target_link_libraries(main Threads::Threads)

## OpenCV
# find_package(OpenCV REQUIRED)
# if(OpenCV_FOUND)
#   include_directories(${OpenCV_INCLUDE_DIRS})
#   target_link_libraries(main ${OpenCV_LIBRARIES})
# endif()
