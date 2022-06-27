find_package(fmt)

add_library(fillToString)
target_sources(fillToString
    PRIVATE
        fillIntToStr.cpp
	PUBLIC
        fillIntToStr.hpp)

target_link_libraries(fillToString PRIVATE fmt::fmt)
target_include_directories(fillToString PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
