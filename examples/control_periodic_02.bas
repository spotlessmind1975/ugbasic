REM @english
REM FLOW CONTROL USING EVERY..CALL
REM
REM This example will use the ''EVERY...CALL'' keywords to change,
REM at each ''TICKS PER SECOND'' ticks, the text on the screen.
REM
REM @italian
REM CONTROLLO DI FLUSSO USANDO EVERY..CALL
REM
REM Questo esempio utilizzerà le parole chiave ''EVERY...CALL'' per cambiare, 
REM ogni ''TICKS PER SECOND' ticks, il testo sullo schermo.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000,cpc

   CLS

PROCEDURE changeText

   SHARED textIndex

   HOME: PRINT "Text index #"; textIndex

   textIndex = textIndex + 1

   EVERY ON

END PROC

   textIndex = 0
   
   EVERY ( TICKS PER SECOND ) TICKS CALL changeText

   EVERY ON
