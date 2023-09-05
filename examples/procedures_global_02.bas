REM @english
REM USER-DEFINED PROCEDURES ALL VARIABLES AS GLOBAL (USING WILDCARD *)
REM
REM This example will show how global variables can be defined using "wildcards".
REM
REM @italian
REM USARE LE PROCEDURE CON VARIABILI GLOBALI (2)
REM
REM Questo esempio mostrerà come definire le variabili globali usando le "wildcard". 
REM
REM @include atari,atarixl,c128

    CLS
   
    GLOBAL "*"

    PROCEDURE testProcedure
        a = a + 1
    END PROC

    a = 42
    PRINT "before call, a = ";a
    testProcedure[]
    PRINT "after call, a = ";a;" (should be 43)"

