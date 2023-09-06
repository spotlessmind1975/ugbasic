REM @english
REM EXPANSION MANAGEMENT COPY FROM AND TO EXPANSION
REM
REM This example shows how to copy data from / to an expansion bank.
REM
REM @italian
REM ESPANSIONE DI MEMORIA COPIARE A/DA ESPANSIONE
REM
REM Questo esempio mostra come copiare dati da o verso un banco di espansione.
REM
REM @include c128,coco

    IF BANK COUNT = 0 THEN
        PRINT "Sorry, this target "
        PRINT "  does not have any memory bank"
    ELSE

        CLS
        
        VAR x AS WORD = 12345
        VAR y AS WORD = 54321

        PRINT "x = ";x;" y = ";y
        
        BANK WRITE ( BANK COUNT - 1 ) FROM VARPTR(x) TO $0100 SIZE 2
        BANK WRITE ( BANK COUNT - 1 ) FROM VARPTR(y) TO $0200 SIZE 2
        BANK READ ( BANK COUNT - 1 ) FROM $0200 TO VARPTR(x) SIZE 2
        BANK READ ( BANK COUNT - 1 ) FROM $0100 TO VARPTR(y) SIZE 2

        PRINT "x = ";x;" y = ";y

    ENDIF