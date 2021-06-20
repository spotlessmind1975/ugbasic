REM @english
REM SCREEN MANIPULATION CHECKING TILEMAP MODE (1)
REM
REM This example shows the various mode to check if tilemap mode is native
REM or emulated. 
REM
REM @italian
REM MANIPOLAZIONE DI SCHERMI CON VERIFICA DELLA MODALITA' TILEMAP (1)
REM
REM Questo esempio mostra i vari modi di verificare se la modalità
REM tilemap è nativa oppure emulata.

   native = BIT( SCREEN, TILEMAP )
   
   IF native THEN
      PRINT "TILEMAP IS NATIVE"
   ELSE
      PRINT "TILEMAP IS EMULATED"
   ENDIF
   
   native = BIT TILEMAP OF SCREEN
   
   IF native THEN
      PRINT "TILEMAP IS NATIVE"
   ELSE
      PRINT "TILEMAP IS EMULATED"
   ENDIF
   
   IF SCREEN HAS BIT TILEMAP THEN
      PRINT "TILEMAP IS NATIVE"
   ELSE
      PRINT "TILEMAP IS EMULATED"
   ENDIF
   
   IF SCREEN IS TILEMAP THEN
      PRINT "TILEMAP IS NATIVE"
   ELSE
      PRINT "TILEMAP IS EMULATED"
   ENDIF

   HALT