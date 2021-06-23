REM @english
REM TEXTS OUTPUT WITH POSITIONING (6)
REM
REM This example shows the use of ''AT'' function and ''LOCATE'' command.
REM This example will draw an hi score on the screen.
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (6)
REM
REM Questo esempio mostra l'uso della funzione ''AT'' e del comando ''LOCATE''.
REM Questo esempio disegnerà l'hi score,

  score=999
  LOCATE 12,10
  PRINT "HI SCORE ";score

  hiscore=AT$(24,10)+"HI SCORE "
  score=999
  PRINT hiscore;score

  HALT