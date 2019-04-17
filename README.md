# Esercitazione con Socket

Esercitazione da svolgere individualmente.

## Svolgimento

Utilizzare la coppia di file `echo-server.c` e `client.c` per inviare e ricevere semplici sequenze di byte da riga di comando, da un processo all'altro, tramite socket.

Il codice d'esempio utilizza una semplice libreria multipiattaforma (nel file `socket-lib.h`), compatibile con WinSock2 su Win32 (utilizzato ad esempio con *TinyCC*, seguendo le [istruzioni di installazione dell'esercitazione in laboratorio](https://github.com/DigiPlatMOOC/pdgt-esercitazione-interfacce-base)) e con le Berkeley socket standard su sistemi POSIX.

### Esercizio 1

Modificare il programma in `echo-server.c` in modo tale da rispondere alterando le lettere precedentemente ricevute tramite socket, convertendo quindi l'input nella medesima stringa in una forma (casuale) di *SpongeBob case*.

Ad esempio, la stringa "Ciao mondo" potrebbe essere convertita in "cIaO mONdO".

### Esercizio 2

A partire dal file d'esempio `client.c`, realizzare un programma che effettua una richiesta HTTP di base, ad esempio:

```
GET / HTTP/1.1
```

ad un server Web qualsiasi (ad esempio usando l'URL `http://example.org`).

La risposta ottenuta va stampata integralmente su `stdout`.
