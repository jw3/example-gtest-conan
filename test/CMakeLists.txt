include(GoogleTest)
link_directories(${CONAN_LIB_DIRS})

add_executable(cache_test CacheTest.cpp)
target_link_libraries(cache_test CONAN_PKG::gtest)
target_include_directories(cache_test PRIVATE ${CMAKE_SOURCE_DIR}/lib)

gtest_add_tests(TARGET cache_test
                SOURCES CacheTest.cpp)
