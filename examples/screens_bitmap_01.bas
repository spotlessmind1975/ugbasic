REM @english
REM SCREEN MANIPULATION CHECKING BITMAP MODE (1)
REM
REM This example shows the various mode to check if bitmap mode is native
REM or emulated. 
REM
REM @italian
REM MANIPOLAZIONE DI SCHERMI CON VERIFICA DELLA MODALITA' BITMAP (1)
REM
REM Questo esempio mostra i vari modi di verificare se la modalità
REM bitmap è nativa oppure emulata.

   native = BIT( SCREEN, BITMAP )
   
   IF native THEN
      PRINT "BITMAP IS NATIVE"
   ELSE
      PRINT "BITMAP IS EMULATED"
   ENDIF
   
   native = BIT BITMAP OF SCREEN
   
   IF native THEN
      PRINT "BITMAP IS NATIVE"
   ELSE
      PRINT "BITMAP IS EMULATED"
   ENDIF
   
   IF SCREEN HAS BIT BITMAP THEN
      PRINT "BITMAP IS NATIVE"
   ELSE
      PRINT "BITMAP IS EMULATED"
   ENDIF
   
   IF SCREEN IS BITMAP THEN
      PRINT "BITMAP IS NATIVE"
   ELSE
      PRINT "BITMAP IS EMULATED"
   ENDIF

   HALT