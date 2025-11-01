REM @english
REM FLOW CONTROL USING MULTIPLE EVERY..GOSUB
REM
REM This example will use the ''EVERY...GOSUB'' keywords to change,
REM at each ''TICKS PER SECOND'' ticks, the text on the screen,
REM with two different timers.
REM
REM @italian
REM CONTROLLO DI FLUSSO USANDO PIU' EVERY..GOSUB
REM
REM Questo esempio utilizzerà le parole chiave ''EVERY...GOSUB'' per cambiare, 
REM ogni ''TICKS PER SECOND' ticks, il testo sullo schermo, con due diversi timers.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

   CLS

   DIM textIndex AS SIGNED BYTE
   DIM textIndex2 AS SIGNED BYTE

   textIndex = 0
   textIndex2 = 0

   EVERY ( TICKS PER SECOND ) TICKS, 0 GOSUB changeText
   EVERY ( TICKS PER SECOND * 2 ) TICKS, 1 GOSUB changeText2

   EVERY ON 0
   EVERY ON 1

   HALT

changeText:

   LOCATE 0, 3: PRINT "1) Text index #"; textIndex;
   
   INC textIndex

   EVERY ON 0

   RETURN

changeText2:

   LOCATE 0,2: PRINT "2) Text index #"; textIndex2
   
   INC textIndex2

   EVERY ON 1

   RETURN
