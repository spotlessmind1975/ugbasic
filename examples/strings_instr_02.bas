REM @english
REM STRING MANIPULATION SEARCH INSIDE A STRING FROM A POSITION (USING INSTR())
REM
REM This example shows how to look for a string inside another string, by using
REM the function ''INSTR'' and giving a starting position. Moreover, it return 
REM the starting position of the string inside the other AFTER the one given,
REM or 0 if there is no such position.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE CON RICERCA ALL'INTERNO (2)
REM
REM Questo esempio mostra come effettuare una ricerca di una stringa all'interno di un'altra
REM stringa, usando la funzione ''INSTR'' a indicando una posizione di partenza. Inoltre, 
REM restituisce la posizione iniziale della stringa all'interno dell'altra SUCCESSIVA
REM alla posizione data, oppure 0 se tale posizione non esiste.
REM
REM @include atari,atarixl

    CLS
    
    PRINT "INSTR(ugBASIC,ugBASIC,2) = ";INSTR( "ugBASIC", "ugBASIC", 2)
    PRINT "INSTR(ugBASIC,A,3) = ";INSTR( "ugBASIC", "A", 3)
    PRINT "INSTR(ugBASIC,A,5) = ";INSTR( "ugBASIC", "A", 5)
