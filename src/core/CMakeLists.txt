add_library(
    nebula-engine-core
    STATIC
    src/core_common/types/return_codes.cpp
    src/core_common/services/servicelocator.cpp
    src/core_common/services/logging/iloggerservice.cpp
    src/core_common/services/logging/consolelogger.cpp
    src/core_common/services/platform/iplatformservice.cpp
    src/core_common/services/platform/linux.cpp
    src/core_common/services/platform/windowglfw.cpp
    src/core_common/services/platform/inputglfw.cpp
)

# publicly make the src directory of this library (eg. can include with core_common/)
target_include_directories(nebula-engine-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# needs to public here for some reason
target_link_libraries(nebula-engine-core PUBLIC spdlog::spdlog glfw)

