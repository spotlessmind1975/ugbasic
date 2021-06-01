   REM functional style
   native = BIT( SCREEN, BITMAP )
   
   IF native THEN
      PRINT "BITMAP IS NATIVE"
   ELSE
      PRINT "BITMAP IS EMULATED"
   ENDIF
   
   REM declarative style
   native = BIT BITMAP OF SCREEN
   
   IF native THEN
      PRINT "BITMAP IS NATIVE"
   ELSE
      PRINT "BITMAP IS EMULATED"
   ENDIF
   
   REM conditional style
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