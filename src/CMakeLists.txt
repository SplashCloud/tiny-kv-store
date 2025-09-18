set(CMAKE_CXX_STANDARD 20)

add_library(tiny_kv_store_lib tiny_kv_store.cpp)
target_include_directories(tiny_kv_store_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)