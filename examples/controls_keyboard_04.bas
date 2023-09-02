REM @english
REM I/O CONTROL KEYBOARD READ (USING SCANSHIFT)
REM
REM This example will run an endless loop (''DO...LOOP'') where the keyboard will be
REM scanned for pressing of any shift key. If this happens, the scan shift value will
REM be printed out.
REM
REM @italian
REM CONTROLLI DI I/O LETTURA TASTIERA (USANDO SCANSHIFT)
REM
REM Questo esempio eseguirà un ciclo infinito (''DO...LOOP'') nel quale si attenderà la
REM pressione di un qualsiasi tasto shift sulla tastiera. Se ciò dovesse accadere,
REM il relativo valore sarà stampato sullo schermo.

    CLS

    DO
        s = SCANSHIFT
        IF s <> 0 THEN
            PRINT s
        ENDIF
    LOOP