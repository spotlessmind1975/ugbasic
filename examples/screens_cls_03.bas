REM @english
REM SCREEN MANIPULATION USING CLS (1)
REM
REM This example shows how to clear the screen using the ''CLS'' command.
REM First of all, the program will ask for a bitmap screen of 320x200 pixel
REM of resolution with 16 colors, by using the ''BITMAP ENABLE'' command.
REM After this, we set the background color to red using the command ''PAPER'',
REM and we clear the screen with a red color (''RED''). Then we wait for 2 seconds
REM and we re-enable the ''TILEMAP'' mode. So we change the background to yellow (''YELLOW'')
REM and, after setting the empty tile to the one with number 48 (lo "0"), we clear the screen again.
REM 
REM
REM @italian
REM MANIPOLAZIONE DI SCHERMI CON L'USO DI CLS (1)
REM
REM Questo esempio mostra come cancellare lo schermo usando il comando ''CLS''. Innanzitutto 
REM il programma richiederà uno schermo bitmap di 320x200 pixel di risoluzione a 16 colori,
REM utilizzando il comando ''BITMAP ENABLE''. Successivamente, impostiamo il colore di sfondo 
REM su rosso utilizzando il comando ''PAPER'' e puliamo lo schermo con un colore rosso (''RED''). 
REM Quindi aspettiamo 2 secondi e riattiviamo la modalità ''TILEMAP''. Quindi cambiamo lo 
REM sfondo in giallo (''YELLOW'') e, dopo aver impostato la tessera vuota su quella con il numero
REM 48 (lo "0"), ripuliamo lo schermo.

    IF CAN SCREEN #1 THEN
        SCREEN #1
        PAPER RED
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #2 THEN
        SCREEN #2
        PAPER GREEN
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #3 THEN
        SCREEN #3
        PAPER BLUE
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #4 THEN
        SCREEN #4
        PAPER RED
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #5 THEN
        SCREEN #5
        PAPER GREEN
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #6 THEN
        SCREEN #6
        PAPER BLUE
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #7 THEN
        SCREEN #7
        PAPER RED
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #8 THEN
        SCREEN #8
        PAPER GREEN
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #9 THEN
        SCREEN #9
        PAPER BLUE
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #10 THEN
        SCREEN #10
        PAPER RED
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #11 THEN
        SCREEN #11
        PAPER GREEN
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #12 THEN
        SCREEN #12
        PAPER BLUE
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #13 THEN
        SCREEN #13
        PAPER RED
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #14 THEN
        SCREEN #14
        PAPER GREEN
        CLS
        WAIT KEY
    ENDIF

    IF CAN SCREEN #15 THEN
        SCREEN #15
        PAPER BLUE
        CLS
        WAIT KEY
    ENDIF

    HALT