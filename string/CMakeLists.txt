project(own)

set(SOURCES
        src/string.cpp
        src/identstr.cpp
        src/binstr.cpp
        )

set(HEADERS
        include/own/string.h
        include/own/identstr.h
        include/own/binstr.h
        )

add_library(string STATIC ${SOURCES} ${HEADERS})
target_include_directories(string PUBLIC include)

# Testing
add_executable(test_string test/test_string.cpp)
target_link_libraries(test_string PUBLIC catch2)
target_link_libraries(test_string PUBLIC string)
add_test(NAME test_string COMMAND test_string)

add_executable(test_identstr test/test_identstr.cpp)
target_link_libraries(test_identstr PUBLIC catch2)
target_link_libraries(test_identstr PUBLIC string)
add_test(NAME test_identstr COMMAND test_identstr)

add_executable(test_binstr test/test_binstr.cpp)
target_link_libraries(test_binstr PUBLIC catch2)
target_link_libraries(test_binstr PUBLIC string)
add_test(NAME test_binstr COMMAND test_binstr)
