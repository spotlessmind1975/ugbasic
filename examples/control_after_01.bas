REM @english
REM FLOW CONTROL USING AFTER..CALL
REM
REM This example will use the ''AFTER...CALL'' keywords to change,
REM after ''TICKS PER SECOND'' ticks, the text on the screen.
REM
REM @italian
REM CONTROLLO DI FLUSSO USANDO AFTER..CALL
REM
REM Questo esempio utilizzerà le parole chiave ''AFTER...CALL'' per cambiare, 
REM dopo ''TICKS PER SECOND' ticks, il testo sullo schermo.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

   CLS

   textIndex = 0

   AFTER ( TICKS PER SECOND ) TICKS CALL changeText

   HALT

PROCEDURE changeText

   HOME: PRINT "Text index #"; textIndex
   
END PROC
