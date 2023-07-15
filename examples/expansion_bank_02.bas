REM @english
REM EXPANSION MANAGEMENT SET A BANK
REM
REM This example will change the current selected bank.
REM
REM @italian
REM ESPANSIONE DI MEMORIA INDIRIZZI E BANCHI
REM
REM Questo esempio cambierà il banco selezionato.

    CLS
    
    PRINT BANK()
    BANK #3
    PRINT BANK()

    FOR i=0 TO BANK COUNT
        IF i = BANK() THEN
            PRINT "*";
        ELSE
            PRINT " ";
        ENDIF
        PRINT BANK ADDRESS(i);" size = "; BANK SIZE(i)
    NEXT

    PRINT "* = actual bank selected"
