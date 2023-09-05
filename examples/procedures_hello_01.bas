REM @english
REM USER-DEFINED PROCEDURES DEFINING A PROCEDURE (BUT NOT CALLING IT)
REM
REM This example will show how to define an user-defined procedure. The definition,
REM by itself, does not mean that the procedure will be executed. Infact, the result
REM of this example is... nothing!
REM
REM @italian
REM USARE LE PROCEDURE DEFINENDOLE (1)
REM
REM Questo esempio mostra come definire una procedura utrente. La definizione,
REM di per sé, non significa che la procedura sarà eseguita. Infatti, il risultato
REM di questo esempio è... nulla! 
REM
REM @include atari,atarixl,c128,c64

   CLS
   
   PROCEDURE hello
      PRINT "HELLO I AM A PROCEDURE!"
   END PROC

   PRINT "(nothing to show)"
