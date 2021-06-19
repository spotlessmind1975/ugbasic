REM @english
REM USER-DEFINED PROCEDURES WITH SHARED VARIABLES (1)
REM
REM This example will show how the shared variables works. First of all, we
REM will declare 2 local variables (''a'' AND ''b'') by using the ''SHARED'' keyword. 
REM Then, we assign a value outside each procedures. Then the procedure
REM is called. The result is that the original value have been
REM changed by procedure execution, since those variables are shared (global).
REM
REM @italian
REM USARE LE PROCEDURE CON VARIABILI CONDIVISE (1)
REM
REM Questo esempio mostrerà come funzionano le variabili condivise. Prima di tutto, 
REM dichiariamo 2 variabili locali (''a'' e ''b'') utilizzando la parola chiave 
REM ''SHARED''. Quindi, assegniamo un valore al di fuori di ciascuna procedura. 
REM La procedura viene quindi chiamata, e il risultato è che 
REM il valore originale è stato modificato dall'esecuzione della procedura, 
REM poiché tali variabili sono condivise (globali). 

   PROCEDURE example
      SHARED a,b
      a = b - a
      b = b + 1
   END PROC

   a = 42
   b = 84

   example

   PRINT "a = ";a
   PRINT "b = ";b

   HALT
