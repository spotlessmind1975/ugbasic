       x = 0
   start:
       GOSUB incrementX
       COLOR BORDER x
       WAIT 500 MS
       GOTO start
       
   incrementX:
       x = x + 1
       IF x > 16 THEN : x = 0 : RETURN : ENDIF
       RETURN
       