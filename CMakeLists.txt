cmake_minimum_required(VERSION 3.10)
project(AlpacaAPI)
set(CMAKE_CXX_STANDARD 17)

# Set correct search paths for Linux
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/")

# Find JsonCpp and Curl
find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)
find_package(CURL REQUIRED)

# Include directories
include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories(${JSONCPP_INCLUDE_DIRS})

# Gather all .cpp files
file(GLOB SOURCES
        src/Account/*.cpp
        src/Asset/*.cpp
        src/Clock/*.cpp
        src/Order/*.cpp
        src/Position/*.cpp
        src/TradeApi/*.cpp
)

# Build the executable
add_executable(AlpacaAPI main.cpp ${SOURCES})

# Link libraries
target_link_libraries(AlpacaAPI PRIVATE ${JSONCPP_LIBRARIES} CURL::libcurl)
