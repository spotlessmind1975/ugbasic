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

    IF BANK COUNT = 0 THEN
        PRINT "Sorry, this target "
        PRINT "  does not have any memory bank"
    ELSE

        PRINT "CURRENT BANK #: "; BANK()
        PRINT "SELECT BANK #3": BANK #3
        PRINT "CURRENT BANK #: "; BANK()

        FOR i=0 TO BANK COUNT - 1
            IF i = BANK() THEN
                PRINT "*";
            ELSE
                PRINT " ";
            ENDIF
            PRINT "AT ";BANK ADDRESS(i);" ("; BANK SIZE(i);" bytes)"
        NEXT

        PRINT "* = actual bank selected"
    ENDIF