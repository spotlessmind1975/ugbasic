REM @english
REM SCREEN MANIPULATION CLEARING SCREEN (USING CLS) (2)
REM
REM This example shows how to clear the screen using the ''CLS'' command.
REM First of all, the program will ask for a bitmap screen of 320x200 pixel
REM of resolution with 16 colors, by using the ''BITMAP ENABLE'' command.
REM After this, we set the background color to red using the command ''PAPER'',
REM and we clear the screen with a white color (''WHITE''). 
REM
REM @italian
REM MANIPOLAZIONE DI SCHERMI CON L'USO DI CLS (2)
REM
REM Questo esempio mostra come cancellare lo schermo usando il comando ''CLS''. Innanzitutto 
REM il programma richiederà uno schermo bitmap di 320x200 pixel di risoluzione a 16 colori,
REM utilizzando il comando ''BITMAP ENABLE''. Successivamente, impostiamo il colore di sfondo 
REM su rosso utilizzando il comando ''PAPER'' e puliamo lo schermo con un colore bianco (''WHITE''). 
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

    BITMAP ENABLE (320,200,16)

    PAPER RED
    CLS WHITE
