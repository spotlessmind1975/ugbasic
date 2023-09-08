REM @english
REM EXPANSION MANAGEMENT LIST OF AVAILABLE BANKS
REM
REM This example prints the starting addresses and the size 
REM of all available memory banks. If the address is 0, this 
REM means that the bank cannot be reached directly with an 
REM access but only through the primitives made available by ugBASIC.
REM
REM @italian
REM ESPANSIONE DI MEMORIA ELENCO DEI BANCHI
REM
REM Questo esempio stampa gli indirizzi di partenza e la dimensione
REM di tutti i banchi di memoria disponibili. Se l'indirizzo vale 0, 
REM questo significa che il banco non è raggiungibile direttamente
REM con un accesso ma solo tramite le primitive messe a disposizione 
REM da ugBASIC.
REM
REM @include c128,coco,d32,d64

    CLS
    
    PRINT "BANK LIST"
    PRINT "---------"
    PRINT

    IF BANK COUNT = 0 THEN
        PRINT "Sorry, this target "
        PRINT "  does not have any memory bank"
    ELSE
        FOR i=0 TO BANK COUNT - 1
            IF i = BANK() THEN
                PRINT "*";
            ELSE
                PRINT " ";
            ENDIF
            PRINT i;") AT ";BANK ADDRESS(i);" ("; BANK SIZE(i);" bytes)"
        NEXT

        PRINT

        PRINT "* = actual bank selected"
    ENDIF