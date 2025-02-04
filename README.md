# Terminal Chess

Implementazione del gioco degli scacchi da terminale in C++ per un progetto di programmazione dell'Università di Padova.

Stile seguito: https://google.github.io/styleguide/cppguide.html

Il programma verifica che siano rispettate e rispetta in ogni caso le regole di scacchi ufficiali e indicate nei seguenti siti:
- https://www.scuolascacchipordenone.eu/le-regole.html 
- https://www.scuolascacchipordenone.eu/le-mosse-speciali-.html
- https://www.scuolascacchipordenone.eu/scacco-scaccomatto-patta-.html

## Creare l'eseguibile
Il progetto è compilabile tramite cmake.

All'interno della cartella, aprire un terminale e lanciare:
```sh
cmake -S . -B ./build
cd build
make
```

## Come giocare
Dalla cartella principale, aprire il terminale e lanciare:
```sh
./build/scacchiera/scacchiera [cc|pc|pp]
```
Dove 'c' sta per computer e 'p' per persona.

Le possibili combinazioni di lettere per le mosse sono:
- A1 B2 : per spostare una pedina da A1 a B2           
- A1 B2 PP: per spostare una pedina da A1 a B2 e chiedere patta all'altro giocatore       
- A1 MM : per visualizzare le mosse disponibili per A1 
- XX XX : per visualizzare la scacchiera completa      
- HE LP : per visualizzare i comandi                   
- FF FF : per lasciare il gioco                        
Il formato delle lettere non influisce (a = A)

Questo messaggio è anche visualizzabile all'interno del programma scrivendo HE LP.

## Come fare il replay di una partita
Dalla cartella principale, aprire il terminale e lanciare:
```sh
./build/replay/replay [v|f] [log_file] [log_output se f]
```
Dove 'v' stampa a video/terminale e 'f' stampa su un file.

## Ulteriori informazioni

Ulteriori dettagli sul progetto sono disponibili nella descrizione generale 'progetto_scacchiera.pdf'.

## Autori

Progetto realizzato da Feild_progect:
- Bassotto Cristian
- Cinel Giovanni
- Nordio Gianluca
