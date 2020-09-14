project(examples CXX)

# CLI
add_executable(cli cli.cpp)
target_link_libraries(cli string)
