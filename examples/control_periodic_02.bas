REM @english
REM FLOW CONTROL WITH PERIODIC CALLS (2)
REM
REM This example will use the ''EVERY...CALL'' keywords to change,
REM at each 50 ticks, the color of the border. The color will be cycled
REM from 0 to the maximum number of colors allowes (''COLOR COUNT'').
REM Note that, each time the routine is called, the mechanism of PERIODIC
REM call will be disabled. To re-enable you have to call ''EVERY ON'' again.
REM The border color is changed using the ''COLOR BORDER'' instruction, using 
REM the integer value assigned to the ''colorIIndex'' variable.
REM
REM @italian
REM CONTROLLO DI FLUSSO CON CHIAMATE PERIODICHE (2)
REM
REM Questo esempio utilizzerà le parole chiave ''EVERY...CALL'' per cambiare, 
REM ogni 50 "tick", il colore del bordo. Il colore verrà ciclizzato da 0 al 
REM numero massimo di colori consentiti (''COLOR COUNT''). Si noti che, ogni 
REM volta che viene chiamata la routine, il meccanismo di chiamata periodica 
REM verrà disabilitato. Per riattivarlo è necessario chiamare di nuovo il comando
REM ''EVERY ON''. Il colore del bordo viene cambiato utilizzando l'istruzione 
REM ''COLOR BORDER'', utilizzando il valore intero assegnato alla variabile 
REM ''colorIIndex''.
REM

PROCEDURE changeBorderColor

   SHARED colorIndex

   COLOR BORDER colorIndex

   colorIndex = colorIndex + 1

   IF colorIndex == COLOR COUNT THEN
      colorIndex = 0
   ENDIF

   EVERY ON

END PROC

   colorIndex = 0
   
   EVERY 50 TICKS CALL changeBorderColor

   EVERY ON

   HALT
