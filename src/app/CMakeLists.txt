add_executable(
    nebula-engine
    src/main.cpp
    src/application/application.cpp
)

target_link_libraries(nebula-engine PRIVATE nebula-engine-core spdlog::spdlog CLI11)

