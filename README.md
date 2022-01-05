# Feild_Progect

Come modificare la cartella senza problemi:
- git pull 
- git add file
- git commit -m "commento"
- git push

Per vedere come e quali file sono stati modiicati o per aiuti
- git status

Per lo stile: https://google.github.io/styleguide/cppguide.html


Da un qualsiasi file cpp con VSCode
- Per compilare facilmente da Visual Studio Code usare ctrl + shift + B
- Per lanciare direttamente senza dover prima compilare usare ctrl + F5
- Per debuggare facilmente da Visual Studio Code premere F5
- Entrambi creano un file eseguibile chiamato Feild_Progect all'interno della cartella build

Con CMake
1) Andare sulla cartella Feild_Progect e da terminale $ cmake -S . -B ./build
2) Entrare su build ($ cd build)
3) Compilare con $ make
4) Eseguire $ ./Feild_Progect

Per Cinel  C:\Users\Giovanni Cinel\Desktop\Università\Laboratorio di programmazione\Feild Progect\Feild_Progect

Per Gianluca C:\Users\Gianluca\Documents\GitHub\Feild_Progect

Per compilare da terminale senza CMake:
- Con Linux: 
$ g++ src/*.cpp
$ ./a.out

- Con Windows
$ g++ src/*.cpp
$ .\a.exe

idee utili:
implementare un vector contenenti i pezzi non mangiati per controllo patta, controllo scacco e scaccomatto

implementare una mappa entry per controllo scacchiera per patta

per lo scacco ritornare un vettore con tutte le posizioni che il pezzo passa per dare scacco (per lo scaccomatto)

implementare un contatore di mosse dall'ultimo oggetto mangiato dentro if(pezzo mangiato != nullpter)

utilizzare il vector di pezzi per controllare se ogni pezzo possa fare almeno una mossa (per lo stallo) per controllare le mosse servono funzioni a parte per ogni classe (senno diventa lento e inutile) basta controllare le caselle vicine per la maggior parte.

per il pareggio per insufficienza di materiale avrò 
- re + alfiere vs re
- re + alfiere o cavallo vs re con alfiere o cavallo
- re + 2 cavalli vs re (o re con 2 cavalli)
- re vs re

richiesta di patta con due lettere dopo la mossa PP


quando realizziamo il metodo della promozione ricordiamo di modi
ficare anche i vector pezzi_bianchi e pezzi_neri

ci mancano:
- scaccomatto
- patta 
- computer
- log
- replay
- capire se eccezioni c++ serve
- commentare
- fare delete finale di tutti gli oggetti usati
- "Nel caso di partite tra due computer, dovete fissare un numero massimo di mosse, oltre il quale la partita è considerata nulla."
- arrocco