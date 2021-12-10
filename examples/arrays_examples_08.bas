REM @english
REM ARRAY MANAGEMENT VARIOUS (1)
REM
REM This small example will test the fix for bug#225.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY ESEMPI VARI (1)
REM
REM Questo piccolo esempio proverà la risoluzione del bug#225.
REM

    CLS
    PRINT "OK!"
    DIM tst$(1)
    tst$(0)="tst"
    NOP
    ' PEN 2
    PRINT tst$(0)
    HALT