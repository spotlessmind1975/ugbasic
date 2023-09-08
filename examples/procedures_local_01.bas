REM @english
REM USER-DEFINED PROCEDURES USING LOCAL VARIABLES (1)
REM
REM This example will demonstrate that the variables, inside the procedures,
REM are always "local". It means that their value will be setted each time
REM the procedure is entered. Moreover, when the procedure ends, their
REM value is lost. So this program will show you that, although an increment
REM of the ''a'' variable is done at each execution, the real value remains
REM always the same.
REM
REM @italian
REM USARE LE PROCEDURE CON VARIABILI LOCALI (1)
REM
REM Questo esempio mostrerà che le variabili all'interno delle procedure sono
REM sempre "locali". Ciò significa che il loro valore sarà impostato ogni qual volta
REM si entra nella procedura. Inoltre, quando la procedura termina, il loro valore
REM andrà perduto. Quindi questo programma dimostrerà che, anche se viene svolto
REM un incremento della variabile ''a'' per ogni esecuzione, il valore effettivo
REM rimarrà sempre il medesimo. 
REM
REM @include atari,atarixl,c128,c64,coco,coleco,cpc

   CLS
   
   PROCEDURE plus
      a = a + 1
      PRINT "a (local) after plus = ";a
   END PROC

   plus[]
   plus[]
   plus[]
   plus[]
