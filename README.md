# Esercitazione con Socket

Esercitazione da svolgere individualmente.

## Svolgimento

A partire dal file d'esempio `socket.c`, realizzare un programma che effettua una richiesta HTTP di base, ad esempio:

```
GET / HTTP/1.1
```

ad un server Web qualsiasi (ad esempio usando l'URL `http://example.org`).

La risposta va stampata integralmente su `stdout`.

Il codice d'esempio utilizza WinSock2 per Win32, ma è chiaramente possibile sfruttare le socket su altre piattaforme.
Per Unix/Linux si può utilizzare il codice in `socket-unix.c` come base di partenza.
