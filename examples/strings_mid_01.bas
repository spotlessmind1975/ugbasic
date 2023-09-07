REM @english
REM STRING MANIPULATION EXTRACT / REPLACE A SUBSTRING (USING MID())
REM
REM This example shows how to extract a string from another string, starting from
REM a specific position and for a given number of characters. The function used is ''MID''.
REM The same function can be used to inject a string, as well.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE ED ESTRAZIONE (3)
REM
REM Questo esempio mostra come si estrare una stringa da un'altra stringa, iniziando
REM da una posizione specifica e per un certo numero di caratteri. La funzione utilizzata è ''MID''.
REM In modo analogo, la stessa funzione può essere usata per iniettare una stringa.
REM
REM @include atari,atarixl,c128,c64,coco,coleco

    CLS

    PRINT "MID(ugBASIC,1) = ";MID("ugBASIC",1)
    PRINT "MID(ugBASIC,2) = ";MID("ugBASIC",2)
    PRINT "MID(ugBASIC,3) = ";MID("ugBASIC",3)
    PRINT "MID(ugBASIC,4) = ";MID("ugBASIC",4)
    PRINT "MID(ugBASIC,5) = ";MID("ugBASIC",5)
    PRINT "MID(ugBASIC,6) = ";MID("ugBASIC",6)

    a = "ugBASIC"

    MID(a, 6, 1) = "X"

    PRINT "a = ";a
