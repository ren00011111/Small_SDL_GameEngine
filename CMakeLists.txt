# CMakeList.txt : CMake project for RTO_CI517_GameEngine_Assessment, include source and define
# project specific logic here.
#
# Enable Hot Reload for MSVC compilers if supported.
 #if (POLICY CMP0141)
 # cmake_policy(SET CMP0141 NEW)
 # set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
# endif()

# project ("RTO_CI517_GameEngine_Assessment")

# Add source to this project's executable.
# add_executable (RTO_CI517_GameEngine_Assessment "RTO_CI517_GameEngine_Assessment.cpp" "RTO_CI517_GameEngine_Assessment.h")

# if (CMAKE_VERSION VERSION_GREATER 3.12)
 # set_property(TARGET RTO_CI517_GameEngine_Assessment PROPERTY CXX_STANDARD 20)
# endif()

# TODO: Add tests and install targets if needed.

# ===============================
# RTO_CI517_GameEngine_Assessment
# commented out previous code for now. 
# code below is a new CMakeLists.txt file that is more organised and 
# includes the SDL library as a subdirectory.


# set the minimum required version of CMake for this project
cmake_minimum_required(VERSION 3.20) # reference https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html

# project declaration 
project(RTO_CI517_GameEngine_Assessment LANGUAGES C CXX) # reference https://cmake.org/cmake/help/latest/command/project.html


# set the c++ standard to 20 
set(CMAKE_CXX_STANDARD 20) # 20 was the standard originally configured for the project, so i have kept it as is.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the output directories for the build 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY) # reference https://cmake.org/cmake/help/latest/variable/CMAKE_RUNTIME_OUTPUT_DIRECTORY.html

# set the library output directory for the build
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    "${CMAKE_BINARY_DIR}/$<CONFIG>") # reference https://cmake.org/cmake/help/latest/variable/CMAKE_LIBRARY_OUTPUT_DIRECTORY.html

# reference for setting output directories: https://cmake.org/cmake/help/latest/command/set.html
# include SDL3 as a subdirectory
add_subdirectory(vendored/SDL-release-3.4.20 EXCLUDE_FROM_ALL)

# create game engine executable
add_executable(RTO_CI517_GameEngine_Assessment
   "RTO_CI517_GameEngine_Assessment.cpp"
    "RTO_CI517_GameEngine_Assessment.h"
)

# link SDL3 library to the game engine
target_link_libraries(RTO_CI517_GameEngine_Assessment # reference https://cmake.org/cmake/help/latest/command/target_link_libraries.html
    PRIVATE SDL3::SDL3
)

# please note: i have included references by relevant lines of code
# as it is easier for me to understand and keep track of each line of code.
# a full harvard style reference list will be included with my assessment in the technical report :)