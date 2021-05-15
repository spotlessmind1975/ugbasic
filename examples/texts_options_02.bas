    REM Target specific control sequence
    USE SPECIFIC
    p$ = PEN$(WHITE)+"WELL ALL WHITE, "+PEN$(YELLOW)+" I STILL GOT THE YELLOW"
    PRINT p$
    PEN RED
    PRINT "IN THE RED"
    REM ANSI control sequence
    USE ANSI
    p$ = PEN$(WHITE)+"WELL ALL WHITE, "+PEN$(YELLOW)+" I STILL GOT THE YELLOW"
    PRINT p$    
    PEN RED
    PRINT "IN THE RED"

    HALT