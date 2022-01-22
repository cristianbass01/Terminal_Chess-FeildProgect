cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE release)
endif()

set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

project(replay VERSION 2.0 DESCRIPTION "Replay della partita a scacchi")

include_directories(./../scacchiera/include)

add_executable(${PROJECT_NAME}
main.cpp
./../scacchiera/include/eccezione.h
./../scacchiera/src/scacchiera.cpp
./../scacchiera/src/computer.cpp
./../scacchiera/src/umano.cpp
./../scacchiera/src/alfiere.cpp
./../scacchiera/src/casella.cpp
./../scacchiera/src/cavallo.cpp
./../scacchiera/src/pedone.cpp
./../scacchiera/src/re.cpp
./../scacchiera/src/regina.cpp
./../scacchiera/src/torre.cpp
./../scacchiera/src/pezzo.cpp
)
