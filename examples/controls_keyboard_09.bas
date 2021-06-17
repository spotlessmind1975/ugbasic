REM @english
REM I/O CONTROL WITH KEYBOARD (9)
REM
REM This example will wait the typing of exactly ten characters.
REM Then, it will print out the same sequence. We note the use of
REM ''CLEAR KEY'' instruction, that clears the keyboard buffer.
REM Moreover, we will use the ''INPUT$()'' function to retrieve
REM the 10 characters.
REM
REM @italian
REM CONTROLLI DI I/O CON LA TASTIERA (9)
REM
REM Questo esempio attende la digitazione di esattamente dieci caratteri.
REM Dopo di che mostrerà a video la medesima sequenza. Da notare l'uso
REM dell'istruzione ''CLEAR KEY'', che svuota il buffer di tastiera.
REM Inoltre, si utiliza la funzione ''INPUT$()'' per recuperare
REM i 10 caratteri.

   CLEAR KEY
   PRINT "PLEASE TYPE IN TEN CHARACTERS"
   v=INPUT$(10)
   PRINT "YOU TYPED: ";v
   HALT
