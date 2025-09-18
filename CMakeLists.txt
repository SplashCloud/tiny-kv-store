cmake_minimum_required(VERSION 3.10)
project(TinyKVStore LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(third_party/googletest)
add_subdirectory(tests)

add_executable(main main.cpp)