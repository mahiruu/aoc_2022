cmake_minimum_required(VERSION 3.25)
project(AOC_2022 C CXX ASM_NASM)

add_subdirectory(src/AOC_2022_lib)

set(CMAKE_CXX_STANDARD 23)

enable_language(ASM_NASM)
set(NASM_COMPILER nasm)
set(CXXFLAGS -O3 -march=native -mtune=native -fno-exceptions -mmmx -fno-rtti -fomit-frame-pointer -fno-stack-ch)
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> <FLAGS> -f ${CMAKE_ASM_NASM_OBJECT_FORMAT}  -o <OBJECT> <SOURCE>")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -no-pie")

set(SOURCE_FILES src/main.cpp)

add_executable(AOC_2022 ${SOURCE_FILES})
target_link_libraries(AOC_2022 PRIVATE AOC_2022_lib)
