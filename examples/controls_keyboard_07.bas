REM @english
REM I/O CONTROL KEYBOARD READ (BIT DECODE KEY SHIFT)
REM
REM This example will show how the various control keys affects the
REM ''KEY SHIFT'' value. We make an infinite loop (''DO...LOOP'') in
REM order to continue to update the bitmask on the screen by using the
REM ''BIN$'' function. This example will show also how to move the
REM output on the screen on a specific position by using the ''LOCATE''
REM and ''CENTRE'' keywords.
REM
REM @italian
REM CONTROLLI DI I/O LETTURA TASTIERA (DECODIFICA BIT DI KEY SHIFT)
REM
REM Questo esempio mostra come i vari tasti controllo influiscano sui
REM bit della variabile di sistema ''KEY SHIFT''. Eseguiamo quindi
REM un loop infinito (''DO...LOOP'') per continuare ad aggiornare
REM il bitmask sullo schermo, usando la funzione ''BIN$''. Questo esempio
REM mostra anche come posizionare l'output sullo schermo, su una posizione specifica,
REM utilizzando i comandi ''LOCATE'' e ''CENTRE'' keywords.

    CLS
    
    CENTRE "PLEASE PRESS SOME CONTROL KEYS"
    DO
        LOCATE 14,4
        PRINT BIN$(KEY SHIFT, 8)
    LOOP