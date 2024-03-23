cmake_minimum_required(VERSION 3.20)

project(f1kart)

# Find OpenMP package
find_package(OpenMP REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp)

# Add executable and link OpenMP
add_executable(f1kart ${SOURCES})
target_link_libraries(f1kart PRIVATE OpenMP::OpenMP_CXX)
