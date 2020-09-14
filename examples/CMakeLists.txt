add_executable(main main.cpp)
target_link_libraries(main string)
install(TARGETS main DESTINATION bin)
