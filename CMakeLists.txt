cmake_minimum_required(VERSION 3.21)
project(Prog2_NHF)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
add_definitions(-DMEMTRACE)
add_executable(Prog2_NHF
        structures/telefonkonyv.cpp
        structures/telefonkonyv.h
        telefonkonyv-main.cpp
        structures/Bejegyzes.h
        structures/Szemely.h structures/Ceg.h
        lib/memtrace.cpp
        lib/memtrace.h structures/Bejegyzes.cpp
        lib/gtest_lite.h)
