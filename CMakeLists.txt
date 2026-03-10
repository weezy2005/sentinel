cmake_minimum_required(VERSION 3.20)

project(sentinel
    VERSION 0.1.0
    DESCRIPTION "Real-time multi-sensor fusion engine for autonomous vehicles"
    LANGUAGES CXX
)

# Require C++20 - we use modern features like concepts and atomic operations
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Show all warnings - good practice, keeps code clean
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# This tells CMake where to find our header files
# Any target that links to sentinel can #include <sentinel/...>
include_directories(include)

# Collect all .cpp source files from src/
file(GLOB_RECURSE SENTINEL_SOURCES
    "src/*.cpp"
)

# Build the main executable
add_executable(sentinel ${SENTINEL_SOURCES})

# Build tests
add_subdirectory(tests)
