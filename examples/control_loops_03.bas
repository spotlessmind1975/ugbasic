REM @english
REM FLOW CONTROL EXITING FROM NESTED LOOP
REM
REM This small example will use the ''DO...LOOP'' keywords to implement
REM an endless loop, and the command ''EXIT n'' to break ''n'' loops. The outer
REM loop will change, at each half of second, the border's color from 
REM black to yellow. The inner loop will change the color of border to red
REM and green. Instead of continuing with the inner loop, this one (and the outer) 
REM will be exited by using the ''EXIT 2'' command.  The border color is
REM changed using the ''COLOR BORDER'' instruction, using the predefined
REM constants ''YELLOW'', ''BLACK'', ''RED'', ''GREEN''. To wait for a specific amount of
REM time the ''WAIT'' command will be used, with the ''MS'' (milliseconds)
REM unit of time.
REM 
REM @italian
REM CONTROLLO DI FLUSSO USCIRE DA UN LOOP INNESTATO
REM
REM Questo piccolo esempio utilizzerà le parole chiave ''DO...LOOP'' per implementare 
REM un ciclo infinito e il comando ''EXIT n'' per interrompere ''n'' cicli. Il ciclo 
REM esterno cambierà, ogni mezzo secondo, il colore del bordo da nero a giallo. 
REM Il ciclo interno cambierà il colore del bordo in rosso e verde. Invece di 
REM continuare con il ciclo interno, questo (e quello esterno) verrà chiuso 
REM utilizzando il comando ''EXIT 2''. Il colore del bordo viene cambiato utilizzando 
REM l'istruzione ''COLOR BORDER'', utilizzando le costanti predefinite ''YELLOW'', 
REM ''BLACK'', ''RED'', ''GREEN''. Per attendere un determinato periodo di tempo 
REM verrà utilizzato il comando ''WAIT'', con l'unità di tempo ''MS'' (millisecondi).
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

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
         COLOR BORDER GREEN
         HOME: PRINT "GREEN "
         WAIT 1000 MS
         DO
            COLOR BORDER RED
            HOME: PRINT "RED   "
            WAIT 1000 MS
            EXIT 2 : REM EXIT 2 = skip 1 more loop, because "EXIT" == "EXIT 1"!
            REM The border will never be green,
            REM and the secondo loop will be skiped
            COLOR BORDER GREEN
            HOME: PRINT "GREEN "
            WAIT 1000 MS
         LOOP
      LOOP
   LOOP

