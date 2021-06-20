REM @english
REM STRING MANIPULATION AND EXTRACTION (2)
REM
REM This example shows how to inject a string into another string, starting from
REM the beginning and arriving to a specific position. The function used is ''LEFT''.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE ED ESTRAZIONE (2)
REM
REM Questo esempio mostra come si inietta una stringa in un'altra stringa, iniziando
REM dal principio ed arrivando a una posizione specifica. La funzione utilizzata è ''LEFT''.

  a$ = "******* COMPILER"

  LEFT$( a$, 7 ) = "UGBASIC"

  PRINT "a$ = ";a$

  HALT