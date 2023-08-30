set(CMAKE_CXX_STANDARD 23)

set(SOURCES days.hpp day1/part1.c hello.asm day1/part2.c day2/part1.c)
add_library(AOC_2022_lib STATIC ${SOURCES})

target_include_directories(AOC_2022_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(AOC_2022_lib PROPERTIES VERSION 1.0 SOVERSION 1)