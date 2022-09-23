cmake_minimum_required(VERSION 3.11.3)

# set(CMAKE_CXX_STANDARD 17)
project(raytracer)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

find_package(Boost 1.74 COMPONENTS program_options REQUIRED)

include_directories(${Boost_INCLUDE_DIR} src/*.h)

# Find all executables
file(GLOB project_SRCS src/*.cpp)

# Add project executable
add_executable(raytracer ${project_SRCS})
target_link_libraries(raytracer ${Boost_LIBRARIES})
