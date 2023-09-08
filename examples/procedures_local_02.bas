REM @english
REM USER-DEFINED PROCEDURES USING LOCAL VARIABLES (2)
REM
REM This example will demonstrate that the variables, inside the procedures,
REM are always "local". It means that their value will be setted each time
REM the procedure is entered. Moreover, when the procedure ends, their
REM value is lost and their value are different from already defined
REM variables at global level, although they have the very same names.
REM
REM @italian
REM USARE LE PROCEDURE CON VARIABILI LOCALI (2)
REM
REM Questo esempio mostrerà che le variabili all'interno delle procedure sono
REM sempre "locali". Ciò significa che il loro valore sarà impostato ogni qual volta
REM si entra nella procedura. Inoltre, quando la procedura termina, il loro valore
REM andrà perduto e il loro valore è diverso da quello di variabili già definite
REM a livello globale, anche se hanno lo stesso nome. 
REM
REM @include atari,atarixl,c128,c64,coco,coleco,cpc

   CLS
   
   a = 42
   b = 84

   PROCEDURE example
      PRINT "a (local) in example = ";a
      PRINT "b (local) in example = ";b
   END PROC

   PRINT "a (global) = ";a
   PRINT "b (global) = ";b

   example[]
