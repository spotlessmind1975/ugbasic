REM @english
REM TEXTS OUTPUT WITH POSITIONING (2)
REM
REM This example shows the use of ''HOME'' command to reset the position of the next
REM output to the upper left coordinates of the screen. 
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (2)
REM
REM Questo esempio mostra l'uso del comando ''HOME'' per reimpostare la posizione della
REM successiva operazione di output sullo schermo.  
  
  CLS
  LOCATE 10,10
  PRINT "MOVING..."
  
  WAIT 1000 MS
  
  HOME
  PRINT "... TO HOME!"

  HALT