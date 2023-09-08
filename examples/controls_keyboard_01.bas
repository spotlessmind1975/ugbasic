REM @english
REM I/O CONTROL KEYBOARD READ (USING INKEY)
REM
REM This example will run an endless loop (''DO...LOOP'') than will check if a key is pressed
REM by using the ''INKEY$'' function. If a key has been pressed, the program will print the
REM message ''"YOU PRESSED A KEY!"''.
REM
REM @italian
REM CONTROLLI DI I/O LETTURA TASTIERA (USANDO INKEY)
REM
REM Questo esempio eseguirà un ciclo infinito (''DO...LOOP'') che controllerà se un tasto 
REM è stato premuto utilizzando la funzione ''INKEY$''. Se è stato premuto un tasto, il 
REM programma stamperà il messaggio ''"YOU PRESSED A KEY!"''.
REM
REM @include atari,atarixl,c128,c64,coco,cpc

    CLS

    DO
        k = INKEY$
        IF k <> "" THEN 
            PRINT "YOU PRESSED A KEY!"
        ENDIF
    LOOP
    