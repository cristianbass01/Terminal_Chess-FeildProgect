cmake_minimum_required(VERSION 3.18.4)


project(replay)

include_directories(./../scacchiera)

add_executable(${PROJECT_NAME}
main.cpp
./../scacchiera/src/scacchiera.cpp
./../scacchiera/src/computer.cpp
./../scacchiera/src/umano.cpp
./../scacchiera/src/eccezione.cpp
./../scacchiera/src/alfiere.cpp
./../scacchiera/src/casella.cpp
./../scacchiera/src/cavallo.cpp
./../scacchiera/src/pedone.cpp
./../scacchiera/src/re.cpp
./../scacchiera/src/regina.cpp
./../scacchiera/src/torre.cpp
./../scacchiera/src/pezzo.cpp
)
