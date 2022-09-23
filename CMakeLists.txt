cmake_minimum_required(VERSION 3.11.3)

# set(CMAKE_CXX_STANDARD 17)
project(traffic_simulation)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

find_package(OpenCV 4.1 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} src/*.h)
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

# Find all executables
file(GLOB project_SRCS src/*.cpp) #

# Add project executable
add_executable(raytracer ${project_SRCS})
target_link_libraries(raytracer ${OpenCV_LIBRARIES})
