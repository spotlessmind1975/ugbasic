REM @english
REM FLOW CONTROL EXITING FROM LOOP
REM
REM This small example will use the ''DO...LOOP'' keywords to implement
REM an endless loop, and the command ''EXIT'' to break a loop. The outer
REM loop will change, at each half of second, the border's color from 
REM black to yellow. The inner loop will change the color of border to red.
REM Instead of continuing with the inner loop, this one will be exited
REM by using the ''EXIT'' command.  The border color is
REM changed using the ''COLOR BORDER'' instruction, using the predefined
REM constants ''YELLOW'', ''BLACK'' and ''RED''. To wait for a specific amount of
REM time the ''WAIT'' command will be used, with the ''MS'' (milliseconds)
REM unit of time.
REM 
REM @italian
REM CONTROLLO DI FLUSSO USCIRE DA UN LOOP
REM
REM Questo piccolo esempio utilizzerà le parole chiave ''DO...LOOP'' per 
REM implementare un ciclo infinito e il comando ''EXIT '' per interrompere un 
REM ciclo. Il ciclo esterno cambierà, ogni mezzo secondo, il colore del bordo da 
REM nero a giallo. Il ciclo interno cambierà il colore del bordo in rosso. Invece 
REM di continuare con il ciclo interno, questo verrà terminato utilizzando il comando 
REM ''EXIT''. Il colore del bordo viene modificato utilizzando l'istruzione 
REM ''COLOR BORDER'', utilizzando le costanti predefinite ''YELLOW'', ''BLACK''
REM e ''RED''. Per attendere un determinato periodo di tempo verrà utilizzato il 
REM comando ''WAIT'', con l'unità di tempo ''MS '' (millisecondi).
REM
REM @include atari,atarixl,c128,c64,coco

   CLS

   DO
      COLOR BORDER YELLOW
      HOME: PRINT "YELLOW"
      WAIT 500 MS
      COLOR BORDER BLACK
      HOME: PRINT "BLACK "
      WAIT 500 MS
      DO
         COLOR BORDER RED
         HOME: PRINT "RED   "
         WAIT 1000 MS
         EXIT
         REM The border will never be green!
         COLOR BORDER GREEN
         HOME: PRINT "GREEN "
         WAIT 1000 MS
      LOOP
   LOOP
   