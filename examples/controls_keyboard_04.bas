REM @english
REM I/O CONTROL WITH KEYBOARD (4)
REM
REM This example will run an endless loop (''DO...LOOP'') where the keyboard will be
REM scanned for pressing of any shift key. If this happens, the scan shift value will
REM be printed out.
REM
REM @italian
REM CONTROLLI DI I/O CON LA TASTIERA (4)
REM
REM Questo esempio eseguirà un ciclo infinito (''DO...LOOP'') nel quale si attenderà la
REM pressione di un qualsiasi tasto shift sulla tastiera. Se ciò dovesse accadere,
REM il relativo valore sarà stampato sullo schermo.

    DO
        s = SCANSHIFT
        IF s <> 0 THEN
            PRINT s
        ENDIF
    LOOP