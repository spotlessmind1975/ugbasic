REM @english
REM STRING MANIPULATION EXTRACT A SUBSTRING (USING RIGHT())
REM
REM This example shows how to extract a string from another string, starting from
REM the end and arriving to a specific position. The function used is ''RIGHT''.
REM The same function can be used to inject a string, as well.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE ED ESTRAZIONE (4)
REM
REM Questo esempio mostra come si estrare una stringa da un'altra stringa, iniziando
REM dalla fine ed arrivando a una posizione specifica. La funzione utilizzata è ''RIGHT''.
REM In modo analogo, la stessa funzione può essere usata per iniettare una stringa.
REM
REM @include atari

    CLS

    a$ = "ugBASIC ********"
    RIGHT$( a$, 8 ) = "COMPILER"
    PRINT "a$ = ";a$

    PRINT "RIGHT$(a$, 8) = ";RIGHT$( a$, 8 )
  