REM @english
REM STRING MANIPULATION REPLACE A SUBSTRING (USING RIGHT())
REM
REM This example shows how to extract a string from another string, starting from
REM the end and arriving to a specific position. The function used is ''RIGHT''.
REM This example checks if fix #231 works.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE ED ESTRAZIONE (5)
REM
REM Questo esempio mostra come si estrare una stringa da un'altra stringa, iniziando
REM dalla fine ed arrivando a una posizione specifica. La funzione utilizzata è ''RIGHT''.
REM Questo esempio verifica se la fix #231 funziona
REM
REM @include atari,atarixl

    CLS
    PRINT RIGHT$("123456",1)
    PRINT RIGHT$("123456",2)
    PRINT RIGHT$("123456",3)
    PRINT RIGHT$("123456",4)
    PRINT RIGHT$("123456",5)
    PRINT RIGHT$("123456",6)
