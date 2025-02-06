cmake_minimum_required(VERSION 3.10)
project(AlpacaAPI)
set(CMAKE_CXX_STANDARD 17)

# Tell the compiler where to find headers under src/
include_directories("${CMAKE_SOURCE_DIR}/src")

# Gather up all of the .cpp files
file(GLOB SOURCES
        src/Account/*.cpp
        src/Asset/*.cpp
        src/Clock/*.cpp
        src/Order/*.cpp
        src/Position/*.cpp
        src/TradeApi/*.cpp
)

# Build one executable (or library) from the .cpp files plus main.cpp
add_executable(AlpacaAPI main.cpp ${SOURCES})
