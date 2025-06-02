# run cmake with <cmake .. -G "MinGW Makefiles"> as we dont have nmake installed from visual studion which is required for the default generator.
# <cmake --build . > 
# <.\Card_War.exe

# remember to do this all in build directory

cmake_minimum_required(VERSION 3.10)

project(Card_War 
    VERSION 0.1
    DESCRIPTION "A simple card game"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "main.cpp")         // as the peroject so far is pretty small and manageable, i just list the files manually. will uncomment and employ this if the project grows larger.

set(SOURCES
    main.cpp
    src/Deck.cpp
)

add_executable(Card_War ${SOURCES})