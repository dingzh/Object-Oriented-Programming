cmake_minimum_required(VERSION 3.12)
project(blockchain)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SRC
        "*.hpp"
        "*.cpp"
        )

add_executable(blockchain ${SRC})