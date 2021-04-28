     x = 0
     y = 0
  start:
     IF x > 16 THEN
        y = 0
     ENDIF
     IF x == 0 THEN
        y = 1
     ENDIF
     IF y == 1 THEN : x = x + 1 : ELSE : x = x - 1 : ENDIF
     COLOR BORDER y + x
     WAIT x * 50 MS
     GOTO start