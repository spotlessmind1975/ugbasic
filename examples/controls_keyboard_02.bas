REM @english
REM I/O CONTROL KEYBOARD READ (USING INKEY AND ASC)
REM
REM This example will run an endless loop (''DO...LOOP'') than will check if a key is pressed
REM by using the ''INKEY$'' function. If a key has been pressed, the program will print the
REM ASCII value of the key pressed.
REM
REM @italian
REM CONTROLLI DI I/O LETTURA TASTIERA (USANDO INKEY E ASC)
REM
REM Questo esempio eseguirà un ciclo infinito (''DO...LOOP'') che controllerà se un tasto è 
REM stato premuto utilizzando la funzione ''INKEY$''. Se è stato premuto un tasto, il programma 
REM stamperà il valore ASCII del tasto premuto.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,cpc,sc3000

    CLS
    
    PRINT "PRESS SOME KEYS TO OBTAIN ASCII VALUE"

    DO
        k = INKEY
        IF k <> "" THEN : PRINT k;" = ";ASC(k) : ENDIF
    LOOP