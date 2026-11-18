add_executable(nebula-engine-core-tests test_main.cpp)

target_link_libraries(nebula-engine-core-tests PRIVATE nebula-engine-core doctest::doctest)
