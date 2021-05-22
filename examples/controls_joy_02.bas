   REM functional style
   left = BIT( JOY(1), LEFT )
   PRINT "LEFT IS: ";left
   REM declarative style
   up = BIT UP OF JOY(1)
   PRINT "UP IS: ";up

   REM conditional style
   IF JOY(1) HAS BIT UP THEN : PRINT "UP" : ENDIF
   IF JOY(1) IS UP THEN : PRINT "UP" : ENDIF

   REM (negative) conditional style
   IF JOY(1) HAS NOT BIT UP THEN : PRINT "NOT UP" : ENDIF
   IF JOY(1) IS NOT UP THEN : PRINT "NOT UP" : ENDIF

   HALT