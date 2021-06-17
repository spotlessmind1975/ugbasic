REM @english
REM I/O CONTROL WITH KEYBOARD (6)
REM
REM This example will run an endless loop (''DO...LOOP'') waiting
REM for a specific key press (keys F1 and A).
REM
REM @italian
REM CONTROLLI DI I/O CON LA TASTIERA (6)
REM
REM Questo esempio rimarrà in attesa in un loop infinito (''DO...LOOP''),
REM aspettando la pressione di un tasto specifico (F1 oppure A).

    DO
        IF KEY STATE(KEY F1) THEN : PRINT "F1!" : ENDIF
        IF KEY STATE(KEY A) THEN : PRINT "A!" : ENDIF
    LOOP
