REM @english
REM EXPANSION MANAGEMENT BANK ADDRESSES AND COUNT
REM
REM This example prints the starting addresses and the size 
REM of all available memory banks. If the address is 0, this 
REM means that the bank cannot be reached directly with an 
REM access but only through the primitives made available by ugBASIC.
REM
REM @italian
REM ESPANSIONE DI MEMORIA INDIRIZZI E BANCHI
REM
REM Questo esempio stampa gli indirizzi di partenza e la dimensione
REM di tutti i banchi di memoria disponibili. Se l'indirizzo vale 0, 
REM questo significa che il banco non è raggiungibile direttamente
REM con un accesso ma solo tramite le primitive messe a disposizione 
REM da ugBASIC.

    CLS
    
    FOR i=0 TO BANK COUNT
        IF i = BANK() THEN
            PRINT "*";
        ELSE
            PRINT " ";
        ENDIF
        PRINT BANK ADDRESS(i);" size = "; BANK SIZE(i)
    NEXT

    PRINT "* = actual bank selected"