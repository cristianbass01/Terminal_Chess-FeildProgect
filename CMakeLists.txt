cmake_minimum_required(VERSION 3.18.4)

project(Feild_Progect)


add_executable(${PROJECT_NAME}
src/main.cpp
)

include_directories(pezzi)

add_library(alfiere
pezzi/include/pezzo.h
pezzi/include/alfiere.h
pezzi/src/alfiere.cpp
)

add_library(cavallo
pezzi/include/pezzo.h
pezzi/include/cavallo.h
pezzi/src/cavallo.cpp
)

add_library(pedone
pezzi/include/pezzo.h    
pezzi/include/pedone.h
pezzi/src/pedone.cpp
)

add_library(re
pezzi/include/pezzo.h
pezzi/include/re.h
pezzi/src/re.cpp
)
add_library(regina
pezzi/include/pezzo.h
pezzi/include/regina.h
pezzi/src/regina.cpp
)
add_library(torre
pezzi/include/pezzo.h
pezzi/include/torre.h
pezzi/src/torre.cpp
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
