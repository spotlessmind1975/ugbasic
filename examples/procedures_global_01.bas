REM @english
REM USER-DEFINED PROCEDURES WITH GLOBAL VARIABLES (1)
REM
REM This example will show how the global variables works. First of all, we
REM will define 2 global variables (''a'' AND ''b'') by using the ''GLOBAL'' keyword. 
REM Then, we assign a value outside each procedures. Then the two procedures
REM are defined and called. The result is that the original value have been
REM changed by each procedure execution, since those variables are global.
REM
REM @italian
REM USARE LE PROCEDURE CON VARIABILI GLOBALI (1)
REM
REM Questo esempio mostrerà come funzionano le variabili globali. Prima di tutto, 
REM definiremo 2 variabili globali (''a'' e ''b'') utilizzando la parola chiave '
REM 'GLOBAL''. Quindi, assegniamo un valore al di fuori di ciascuna procedura. 
REM Quindi le due procedure vengono definite e chiamate. Il risultato è che 
REM il valore originale è stato modificato ad ogni esecuzione della procedura, 
REM poiché tali variabili sono globali. 

   GLOBAL a, b
   
   a = 6
   b = 9
   
   PROCEDURE test1
      a = a + 1
      b = b + 1
   END PROC
   
   PROCEDURE test2
      a = a + b
      b = b + a
   END PROC

   test1
   test2
   
   PRINT "a = ";a
   PRINT "b = ";b

   HALT