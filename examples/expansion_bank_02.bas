REM @english
REM EXPANSION MANAGEMENT SET A BANK
REM
REM This example will change the current selected bank.
REM
REM @italian
REM ESPANSIONE DI MEMORIA INDIRIZZI E BANCHI
REM
REM Questo esempio cambierà il banco selezionato.
REM
REM @include c128,coco,d32,d64

    CLS

    IF BANK COUNT = 0 THEN
        PRINT "Sorry, this target "
        PRINT "  does not have any memory bank"
    ELSE

        PRINT "CURRENT BANK #: "; BANK()
        PRINT
        PRINT "SELECT BANK #";(BANK COUNT - 1)
        PRINT
        BANK #(BANK COUNT - 1)
        PRINT "CURRENT BANK #: "; BANK()
        PRINT

        FOR i=0 TO BANK COUNT - 1
            IF i = BANK() THEN
                PRINT "*";
            ELSE
                PRINT " ";
            ENDIF
            PRINT i;") AT ";BANK ADDRESS(i);" ("; BANK SIZE(i);" bytes)"
        NEXT

        PRINT "* = actual bank selected"
    ENDIF