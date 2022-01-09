cmake_minimum_required(VERSION 3.18.4)


project(replay)

include_directories(./../Scacchiera)

add_executable(${PROJECT_NAME}
main.cpp
./../Scacchiera/src/scacchiera.cpp
./../Scacchiera/src/computer.cpp
./../Scacchiera/src/umano.cpp
./../Scacchiera/src/eccezione.cpp
./../Scacchiera/src/alfiere.cpp
./../Scacchiera/src/casella.cpp
./../Scacchiera/src/cavallo.cpp
./../Scacchiera/src/pedone.cpp
./../Scacchiera/src/re.cpp
./../Scacchiera/src/regina.cpp
./../Scacchiera/src/torre.cpp
./../Scacchiera/src/pezzo.cpp
)
