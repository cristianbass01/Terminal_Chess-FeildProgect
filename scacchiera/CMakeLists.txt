cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE release)
endif()

set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

project(scacchiera VERSION 2.0 DESCRIPTION "Gioco di scacchi")

include_directories(./include)
include_directories(./src)

add_executable(scacchiera
main.cpp
src/scacchiera.cpp
src/computer.cpp
src/umano.cpp
src/alfiere.cpp
src/casella.cpp
src/cavallo.cpp
src/pedone.cpp
src/re.cpp
src/regina.cpp
src/torre.cpp
src/pezzo.cpp
)

add_library(alfiere SHARED
include/eccezione.h
include/pezzo.h
include/alfiere.h
src/alfiere.cpp
)

add_library(cavallo SHARED
include/eccezione.h
include/pezzo.h
include/cavallo.h
src/cavallo.cpp
)

add_library(pedone SHARED
include/eccezione.h
include/pezzo.h    
include/pedone.h
src/pedone.cpp
)

add_library(re SHARED
include/eccezione.h
include/pezzo.h
include/re.h
src/re.cpp
)
add_library(regina SHARED
include/eccezione.h
include/pezzo.h
include/regina.h
src/regina.cpp
)
add_library(torre SHARED
include/eccezione.h
include/pezzo.h
include/torre.h
src/torre.cpp
)

add_library(casella SHARED
include/eccezione.h
include/casella.h
src/casella.cpp
)

add_library(computer SHARED
include/eccezione.h
include/giocatore.h
include/computer.h
src/computer.cpp
)

add_library(scacchi SHARED
include/eccezione.h
include/scacchiera.h
src/scacchiera.cpp
)

add_library(umano SHARED
include/eccezione.h
include/giocatore.h
include/umano.h
src/umano.cpp
)

add_library(pezzo SHARED
include/eccezione.h
include/pezzo.h
src/pezzo.cpp
)

target_link_libraries(
alfiere
cavallo
pedone
re
regina
torre
casella
computer
scacchi
umano
pezzo
)
