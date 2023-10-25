# CMakeList.txt : CMake project for CPTS_223_MA2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.16)

# Add source to this project's executable.
add_executable (CPTS_223_MA2 "main.cpp" "BST.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPTS_223_MA2 PROPERTY CXX_STANDARD 20)
endif()

