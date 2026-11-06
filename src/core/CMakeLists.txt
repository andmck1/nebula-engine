add_library(
    nebula-engine-core
    STATIC
    src/core_common/types/return_codes.cpp
    src/core_common/services/logging/iloggerservice.cpp
    src/core_common/services/logging/consolelogger.cpp
    src/core_common/services/servicelocator.cpp
)

# publicly make the src directory of this library (eg. can include with core_common/)
target_include_directories(nebula-engine-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(nebula-engine-core PRIVATE spdlog::spdlog)

