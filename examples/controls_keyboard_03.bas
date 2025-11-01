REM @english
REM I/O CONTROL KEYBOARD READ (USING INKEY AND SCANCODE)
REM
REM This example will run an endless loop (''DO...LOOP'') with an inner loop (''WHILE...WEND'')
REM that waits for a key press. When the key is pressed, the code will check if the key has
REM an ASCII code or not, and to print the fact. Moreover, for each key pressed, the scan code
REM is printed back.
REM
REM @italian
REM CONTROLLI DI I/O LETTURA TASTIERA (USANDO INKEY E SCANCODE)
REM
REM Questo esempio eseguirà un ciclo infinito (''DO...LOOP'') con un ciclo interno (''WHILE...WEND'')
REM che attende la pressione di un tasto. Alla pressione del tasto il codice verificherà se la 
REM chiave ha o meno un codice ASCII e stamperà il fatto. Inoltre, per ogni tasto premuto, viene 
REM ristampato lo scan code.
REM
REM @include coco,coco3,d32,d64,sc3000

    CLS
    
    k = ""
    DO
        WHILE k == ""
            k = INKEY$
        WEND
        IF ASC(k)==0 THEN : PRINT "NO ASCII CODE" : ENDIF
        PRINT "THE SCAN CODE IS ";SCANCODE
        k = ""
    LOOP
