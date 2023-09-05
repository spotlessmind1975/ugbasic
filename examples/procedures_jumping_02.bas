REM @english
REM USER-DEFINED PROCEDURES EXITING FROM A PROCEDURE
REM
REM This small example will show a way to exit from a procedure,
REM when executing it. The trick is done by using the instruction
REM ''POP PROC''. This instruction will stop the current procedure
REM execution and it continue from the point the procedure was
REM called.
REM 
REM @italian
REM USARE LE PROCEDURE USCENDONE (1)
REM
REM Questo piccolo esempio mostra un modo per uscire da una procedura,
REM quando si è in esecuzione all'interno della stessa. Il trucco è
REM di usare l'istruzione ''POP PROC''. Questa istruzione interromperà
REM la procedura corrente, e il programma continuerà l'esecuzione dal punto
REM in cui la procedura è stata chiamata.
REM
REM @include atari,atarixl,c128

   CLS
   
   PROCEDURE escape
      FOR prison = 1 TO 1000000000
         IF prison == 10 THEN : POP PROC : ENDIF
         PRINT "I AM ABANDONED."
      NEXT
   END PROC

   escape[]

   PRINT "I AM FREE!"

   HALT