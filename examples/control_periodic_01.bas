REM @english
REM FLOW CONTROL USING EVERY..GOSUB
REM
REM This example will use the ''EVERY...GOSUB'' keywords to change,
REM at each ''TICKS PER SECOND'' ticks, the text on the screen.
REM
REM @italian
REM CONTROLLO DI FLUSSO USANDO EVERY..GOSUB
REM
REM Questo esempio utilizzerà le parole chiave ''EVERY...GOSUB'' per cambiare, 
REM ogni ''TICKS PER SECOND' ticks, il testo sullo schermo.
REM
REM @include atari,atarixl,c128,c64,coco

   CLS

   textIndex = 0

   EVERY ( TICKS PER SECOND ) TICKS GOSUB changeText

   EVERY ON

   HALT

changeText:

   HOME: PRINT "Text index #"; textIndex
   
   textIndex = textIndex + 1

   EVERY ON

   RETURN
