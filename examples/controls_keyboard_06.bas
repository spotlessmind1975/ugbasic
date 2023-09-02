REM @english
REM I/O CONTROL KEYBOARD READ (USING KEY STATE)
REM
REM This example will run an endless loop (''DO...LOOP'') waiting
REM for a specific key press (keys F1 or A).
REM
REM @italian
REM CONTROLLI DI I/O LETTURA TASTIERA (USANDO KEY STATE)
REM
REM Questo esempio rimarrà in attesa in un loop infinito (''DO...LOOP''),
REM aspettando la pressione di un tasto specifico (F1 oppure A).
REM
REM @include atari

    CLS

    DO
        IF KEY STATE(KEY F1) THEN : PRINT "F1!" : ENDIF
        IF KEY STATE(KEY A) THEN : PRINT "A!" : ENDIF
    LOOP
