cmake_minimum_required(VERSION 3.21)
project(Prog2_NHF)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
add_definitions(-DMEMTRACE)
add_executable(Prog2_NHF
        telefonkonyv.cpp
        telefonkonyv.h
        telefonkonyv-main.cpp
        Bejegyzes.h
        Szemely.h Ceg.h
        memtrace.cpp
        memtrace.h Bejegyzes.cpp
        gtest_lite.h)
