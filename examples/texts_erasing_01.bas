REM @english
REM TEXTS OUTPUT WITH ERASING (1)
REM
REM This example shows how to remove a part of a line and an entire line by using the ''CLINE'' command.
REM
REM @italian
REM STAMPA DI TESTI CON CANCELLAZIONE (1)
REM
REM Questo esempio mostra come cancellare parte di una riga e una riga intera, usando l'istruzione ''CLINE''.

  CLS
  
  LOCATE 0,1
  PRINT "TESTING TESTING TESTING";

  LOCATE 0,3
  PRINT "TESTING TESTING TESTING";

  CMOVE -7,
  CLINE 7
  
  LOCATE 0,1
  CLINE
  
  HALT