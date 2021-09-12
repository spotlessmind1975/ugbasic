REM @english
REM USER-DEFINED PROCEDURES WITH GLOBAL VARIABLES (2)
REM
REM This example will show how global variables can be defined using "wildcards".
REM
REM @italian
REM USARE LE PROCEDURE CON VARIABILI GLOBALI (2)
REM
REM Questo esempio mostrerà come definire le variabili globali usando le "wildcard". 

    GLOBAL "*"

    PROCEDURE test
        a = a + 1
    END PROC

    a = 42
    PRINT "before call, a = ";a
    test
    PRINT "after call, a = ";a;" (should be 43)"

    HALT
