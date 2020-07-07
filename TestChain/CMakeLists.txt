# CMakeList.txt : CMake project for TestChain, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (TestChain "main.cpp" "Block.cpp" "Block.h" "Blockchain.cpp" "Blockchain.h" "sha256.cpp" "sha256.h")
