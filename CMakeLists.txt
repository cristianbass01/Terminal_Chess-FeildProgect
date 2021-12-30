cmake_minimum_required(VERSION 3.18.4)


project(Feild_Progect)

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
)

include_directories(pezzi)

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

add_library(scacchiera
include/scacchiera.h
src/scacchiera.cpp
)

add_library(umano
include/giocatore.h
include/umano.h
src/umano.cpp
)

target_link_libraries(${PROJECT_NAME}
alfiere
cavallo
pedone
re
regina
torre
casella
computer
eccezione
scacchiera
umano
)
