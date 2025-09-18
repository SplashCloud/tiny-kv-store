set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE TINY_KV_STORE_TEST_SOURCES "${PROJECT_SOURCE_DIR}/tests/*test.cpp") # find all the test file

foreach(test_source ${TINY_KV_STORE_TEST_SOURCES})
    get_filename_component(test_filename ${test_source} NAME)
    string(REPLACE ".cpp" "" test_name ${test_filename})
    add_executable(${test_name} ${test_source})

    target_link_libraries(${test_name}
        PRIVATE
        tiny_kv_store_lib
        GTest::gtest
        GTest::gtest_main
    )
endforeach()
