    PRINT SCANSHIFT
    
    REM functional style
    left = BIT( SCANSHIFT, LEFT SHIFT )
    PRINT "LEFT IS: ";left
    
    REM declarative style
    left = BIT LEFT SHIFT OF SCANSHIFT
    PRINT "LEFT IS: ";up
    
    REM conditional style
    IF SCANSHIFT HAS BIT LEFT SHIFT THEN : PRINT "LEFT" : ENDIF
    IF SCANSHIFT IS LEFT SHIFT THEN : PRINT "LEFT" : ENDIF
    
    REM (negative) conditional style
    IF SCANSHIFT HAS NOT BIT LEFT SHIFT THEN : PRINT "NOT LEFT" : ENDIF
    IF SCANSHIFT IS NOT LEFT SHIFT THEN : PRINT "NOT LEFT" : ENDIF

    HALT