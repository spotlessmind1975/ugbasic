REM @english
REM TEXTS OUTPUT ERASING TEXT (USING CLINE)
REM
REM This example shows how to remove a part of a line and an entire line by using the ''CLINE'' command.
REM
REM @italian
REM STAMPA DI TESTI CON CANCELLAZIONE (1)
REM
REM Questo esempio mostra come cancellare parte di una riga e una riga intera, usando l'istruzione ''CLINE''.
REM
REM @include atari,atarixl,c128

  CLS
  
  LOCATE 0,1
  PRINT "THIS LINE WILL BE ERASED";

  LOCATE 0,3
  PRINT "THE WORD WILL BE ERASED";

  CMOVE -7,
  CLINE 7
  
  LOCATE 0,1
  CLINE
  
