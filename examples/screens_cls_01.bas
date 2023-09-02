REM @english
REM SCREEN MANIPULATION CLEARING SCREEN (USING CLS) (1)
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
REM
REM @include atari

    BITMAP ENABLE (320,200,16)
    
    PAPER RED
    CLS

    WAIT 1000 MS

    TILEMAP ENABLE
    PAPER YELLOW
    EMPTY TILE = 48

    CLS
