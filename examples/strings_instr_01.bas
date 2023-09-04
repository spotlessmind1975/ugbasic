REM @english
REM STRING MANIPULATION SEARCH INSIDE A STRING (USING INSTR())
REM
REM This example shows how to look for a string inside another string, by using
REM the function ''INSTR''. Moreover, it return the starting position of the string
REM inside the other, or 0 if there is no such position.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE CON RICERCA ALL'INTERNO (1)
REM
REM Questo esempio mostra come effettuare una ricerca di una stringa all'interno di un'altra
REM stringa, usando la funzione ''INSTR''. Inoltre, restituisce la posizione iniziale
REM della stringa all'interno dell'altra, oppure 0 se tale posizione non esiste.
REM
REM @include atari,atarixl

    CLS

    PRINT "INSTR(ugBASIC,ugBASIC) = ";INSTR( "ugBASIC", "ugBASIC") 
    PRINT "INSTR(ugBASIC,O) = ";INSTR( "ugBASIC", "O")
    PRINT "INSTR(ugBASIC,A) = ";INSTR( "ugBASIC", "A")
