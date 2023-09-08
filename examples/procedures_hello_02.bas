REM @english
REM USER-DEFINED PROCEDURES CALL A PROCEDURE (USING [])
REM
REM This example will show how to define an user-defined procedure. The definition,
REM by itself, does not mean that the procedure will be executed. Infact, we call
REM the procedure just after defining it. The result is the string ''"HELLO I AM A PROCEDURE!"''
REM sullo schermo.
REM
REM @italian
REM USARE LE PROCEDURE DEFINENDOLE (2)
REM
REM Questo esempio mostra come definire una procedura utrente. La definizione,
REM di per sé, non significa che la procedura sarà eseguita. Infatti, chiameremo
REM subito la procedura appena l'abbiamo definita. Il risultato è la stringa 
REM ''"HELLO I AM A PROCEDURE!"'' sullo schermo.
REM
REM @include atari,atarixl,c128,c64,coco,coleco,cpc

   CLS
   
  PROCEDURE hello
    PRINT "HELLO I AM A PROCEDURE!"
  END PROC

  hello[]
