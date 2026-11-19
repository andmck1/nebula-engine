add_executable(nebula-engine-core-tests test_main.cpp
core_common/services/logging/test_iloggerservice.cpp
core_common/services/logging/test_consolelogger.cpp
)

target_link_libraries(nebula-engine-core-tests PRIVATE nebula-engine-core doctest::doctest)
