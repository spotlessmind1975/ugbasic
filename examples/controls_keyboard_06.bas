REM @english
REM I/O CONTROL KEYBOARD READ (USING KEY STATE)
REM
REM This example will run an endless loop (''DO...LOOP'') waiting
REM for a specific key press (keys A or B).
REM
REM @italian
REM CONTROLLI DI I/O LETTURA TASTIERA (USANDO KEY STATE)
REM
REM Questo esempio rimarrà in attesa in un loop infinito (''DO...LOOP''),
REM aspettando la pressione di un tasto specifico (A oppure B).
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,cpc

    CLS

    DO
        IF KEY STATE(KEY A) THEN : PRINT "A!" : ENDIF
        IF KEY STATE(KEY B) THEN : PRINT "B!" : ENDIF
    LOOP
