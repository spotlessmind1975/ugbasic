REM @english
REM FLOW CONTROL USING GOSUB..RETURN (2)
REM 
REM This example will show the use of ''GOSUB...RETURN'' keywords. The main code
REM will change the border color. Each color will last for half second on the screen. 
REM The variable with the color is ''x'' and this is increased with a specific routine,
REM called by ''GOSUB''. To exit the routine a ''RETURN'' will be called. Note that
REM there are two ''RETURN'' instructions, because there is no need for a single
REM point of exit when a routine is called by ''GOSUB''. The border color is changed using the 
REM ''COLOR BORDER'' instruction. To wait for a specific amount of time the ''WAIT'' command will be 
REM used, with the ''MS'' (milliseconds) unit of time.
REM 
REM @italian
REM CONTROLLO DI FLUSSO USANDO GOSUB..RETURN (2)
REM
REM Questo esempio mostrerà l'uso delle parole chiave ''GOSUB...RETURN''. Il codice principale 
REM cambierà il colore del bordo. Ogni colore durerà per mezzo secondo sullo schermo. La variabile con il 
REM colore è ''x'' e questa viene incrementata con una routine specifica, chiamata da ''GOSUB''. 
REM Per uscire dalla routine si usa il comando ''RETURN''. Da notare che vi sono due istruzioni ''RETURN'', 
REM perché non c'è bisogno di un singolo punto di uscita quando una routine viene chiamata da ''GOSUB''.
REM Il colore del bordo viene modificato utilizzando l'istruzione ''COLOR BORDER''. 
REM Per attendere un determinato periodo di tempo verrà utilizzato il comando ''WAIT'', con 
REM l'unità di tempo ''MS'' (millisecondi).
REM
REM @include atari,atarixl

    CLS

    x = 0
start:
    GOSUB incrementX
    COLOR BORDER x
    HOME: PRINT x
    WAIT 500 MS
    GOTO start

incrementX:
    x = x + 1
    IF x > COLOR COUNT THEN : x = 0 : RETURN : ENDIF
    RETURN
