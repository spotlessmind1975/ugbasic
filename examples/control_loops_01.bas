REM @english
REM FLOW CONTROL BY LOOPS (1)
REM
REM This small example will use the ''DO...LOOP'' keywords to implement
REM an endless loop. The loop will change, at each half of second, the
REM border's color from black to yellow and back. The border color is
REM changed using the ''COLOR BORDER'' instruction, using the predefined
REM constants ''YELLOW'' and ''BLACK''. To wait for a specific amount of
REM time the ''WAIT'' command will be used, with the ''MS'' (milliseconds)
REM unit of time.
REM 
REM @italian
REM CONTROLLO DI FLUSSO CON LOOP (1)
REM
REM Questo piccolo esempio utilizzerà le parole chiave ''DO...LOOP'' per 
REM implementare un ciclo infinito. Il ciclo cambierà, ogni mezzo secondo, 
REM il colore del bordo da nero a giallo e viceversa. Il colore del bordo 
REM viene modificato utilizzando l'istruzione ''COLOR BORDER'', utilizzando 
REM le costanti predefinite ''YELLOW'' e ''BLACK''. Per attendere un 
REM determinato periodo di tempo verrà utilizzato il comando ''WAIT'', 
REM con l'unità di tempo ''MS'' (millisecondi).
REM

   DO
      COLOR BORDER YELLOW
      HOME: PRINT "YELLOW"
      WAIT 500 MS
      COLOR BORDER BLACK
      HOME: PRINT "BLACK "
      WAIT 500 MS
   LOOP