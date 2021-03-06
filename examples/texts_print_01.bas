REM @english
REM TEXTS OUTPUT WITH PRINT (9)
REM
REM This example shows the usage of ''PRINT'', by making a loop that
REM prints all characters with the use of ''ASC''.
REM
REM @italian
REM STAMPA DI TESTI CON PRINT (9)
REM
REM Questo esempio mostra l'uso di ''CDOWN'', che incorpora un comando
REM in una stringa per spostare il cursore in basso di 1 carattere.

   TILEMAP ENABLE

   FOR c = 34 TO 64
      PRINT CHR$(c);" = CODE ";
      PRINT ASC(CHR$(c))
   NEXT

   WAIT KEY

   HALT