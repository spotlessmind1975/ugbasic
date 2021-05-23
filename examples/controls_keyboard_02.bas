    PRINT "USE YOUR CURSOR KEY"
    DO
        k = INKEY
        IF k <> "" THEN : PRINT k;XCURS;" ";YCURS; : ENDIF
    LOOP