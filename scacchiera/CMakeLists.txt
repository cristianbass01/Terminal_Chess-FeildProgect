cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE release)
endif()

set(CMAKE_CXX_FLAGS "-O2")
set(CMAKE_CXX_FLAGS_DEBUG "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

project(scacchiera)

include_directories(${PROJECT_NAME}/include)
    
add_executable(${PROJECT_NAME}
src/main.cpp
src/scacchiera.cpp
src/computer.cpp
src/umano.cpp
src/eccezione.cpp
src/alfiere.cpp
src/casella.cpp
src/cavallo.cpp
src/pedone.cpp
src/re.cpp
src/regina.cpp
src/torre.cpp
src/pezzo.cpp
)

add_library(alfiere
include/pezzo.h
include/alfiere.h
src/alfiere.cpp
)

add_library(cavallo
include/pezzo.h
include/cavallo.h
src/cavallo.cpp
)

add_library(pedone
include/pezzo.h    
include/pedone.h
src/pedone.cpp
)

add_library(re
include/pezzo.h
include/re.h
src/re.cpp
)
add_library(regina
include/pezzo.h
include/regina.h
src/regina.cpp
)
add_library(torre
include/pezzo.h
include/torre.h
src/torre.cpp
)

add_library(casella
include/casella.h
src/casella.cpp
)

add_library(computer
include/giocatore.h
include/computer.h
src/computer.cpp
)

add_library(eccezione
include/eccezione.h
src/eccezione.cpp
)

add_library(scacchi
include/scacchiera.h
src/scacchiera.cpp
)

add_library(umano
include/giocatore.h
include/umano.h
src/umano.cpp
)

add_library(pezzo
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
eccezione
scacchi
umano
pezzo
)
