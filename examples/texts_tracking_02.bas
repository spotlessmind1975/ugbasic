REM @english
REM TEXTS OUTPUT GET TEXT POSITION (USING MEMORIZE/REMEMBER)
REM
REM This example shows the use of ''XCURS'' and ''YCURS'' function.
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (10)
REM
REM Questo esempio mostra l'uso di ''XCURS'' oppure ''YCURS'', che incorpora un comando
REM in una stringa per spostare il cursore in basso di 1 carattere.
REM
REM @include c128,coco,d32,d64,coleco,cpc

  CLS
  LOCATE 10,10
  PRINT "10,10";
  MEMORIZE
  LOCATE 12,12
  PRINT "12,12"

  REMEMBER

  PRINT " > REMEMBERED 1"

  REMEMBER
  
  PRINT " > REMEMBERED 2"
