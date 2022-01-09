cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE release)
endif()

set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

project(Feild_Progect)

add_subdirectory(replay)

add_subdirectory(scacchiera)
