   REM functional style
   native = BIT( SCREEN, TILEMAP )
   
   IF native THEN
      PRINT "TILEMAP IS NATIVE"
   ELSE
      PRINT "TILEMAP IS EMULATED"
   ENDIF
   
   REM declarative style
   native = BIT TILEMAP OF SCREEN
   
   IF native THEN
      PRINT "TILEMAP IS NATIVE"
   ELSE
      PRINT "TILEMAP IS EMULATED"
   ENDIF
   
   REM conditional style
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