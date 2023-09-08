REM @english
REM FLOW CONTROL USING IF..THEN..ELSE
REM
REM This small example will use the ''IF...THEN...ELSE...ENDIF'' keywords to implement
REM a endless loop, changing the color of the border in a deterministic way.
REM 
REM @italian
REM CONTROLLO DI USANDO IF..THEN..ELSE
REM
REM Questo piccolo esempio utilizza le istruzioni ''IF...THEN...ELSE...ENDIF''
REM per implementare un loop senza fine, che cambia il colore del bordo in modo
REM deterministico.
REM
REM @include atari,atarixl,c128,c64,coco,coleco,cpc

   CLS

   x = 0
   y = 0
start:
   IF x > 16 THEN
      y = 0
   ENDIF
   IF x = 0 THEN
      y = 1
   ENDIF
   IF y = 1 THEN : x = x + 1 : ELSE : x = x - 1 : ENDIF
   COLOR BORDER y + x
   LOCATE 10, 10: PRINT "x = ";x;" y = ";y;"    "
   WAIT x * 50 MS
   GOTO start