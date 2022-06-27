find_package(Catch2)

add_executable(funTest funTest.cpp)

target_link_libraries(funTest Catch2::Catch2 fillToString)

include(CTest)
include(Catch)
catch_discover_tests(funTest)
