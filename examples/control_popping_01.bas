      x = 0
      y = 0
   start:
      x = x + 1
      COLOR BORDER x + y
      GOSUB incrementX
      GOTO start
      
   nextCycle:
      y = y + 1
      IF y > 7 THEN : y = 0 : ENDIF
      GOTO start
      
   incrementX:
      IF x > 7 THEN : POP : x = 0 : GOTO nextCycle : ENDIF
      RETURN