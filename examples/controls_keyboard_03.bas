    k = ""
    DO
        WHILE k == ""
            k = INKEY$
        WEND
        IF ASC(k)==0 THEN : PRINT "NO ASCII CODE" : ENDIF
        PRINT "THE SCAN CODE IS ";SCANCODE
        k = ""
    LOOP