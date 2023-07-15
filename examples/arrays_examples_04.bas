REM @english
REM ARRAY MANAGEMENT ACCESSING (3)
REM
REM This small example will show how to change just a single element
REM of the array.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY ACCESSO (2)
REM
REM Questo piccolo esempio mostra come cambiare un singolo elemento dell'array.
REM

CLS

DIM array AS BYTE (6,7)

PRINT "array(0,0) = ";array(0,0)
PRINT "array(5,0) = ";array(5,0)
PRINT "array(0,6) = ";array(0,6)
PRINT "array(5,6) = ";array(5,6)

array(0,0) = 1

PRINT

PRINT "array(0,0) = ";array(0,0)
PRINT "array(5,0) = ";array(5,0)
PRINT "array(0,6) = ";array(0,6)
PRINT "array(5,6) = ";array(5,6)


