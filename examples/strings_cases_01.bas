REM @english
REM STRING MANIPULATION WITH LOWER AND UPPER CASES (1)
REM
REM This example shows how to convert from lower case to upper case,
REM and viceversa, by using the string function ''LOWER'' and ''UPPER''.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE MAIUSCOLE / MINUSCOLE (1)
REM
REM Questo esempio mostra come convertire stringhe da minuscolo a maiuscolo,
REM e viceversa, usando le funzioni ''LOWER'' e ''UPPER''.

    PRINT "UPPER(ugBASIC) = ";UPPER$("ugBASIC")
    PRINT "LOWER(ugBASIC) = ";LOWER$("ugBASIC")
    PRINT "UPPER(LOWER(ugBASIC)) = ";UPPER$(LOWER$("ugBASIC"))
    HALT
