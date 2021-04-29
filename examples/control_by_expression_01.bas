     times = 1
   start:
     ON times GOTO first, second, third
   nextLoop:
     times = times + 1
     IF times > 3 THEN
        times = 1
     ENDIF
     GOTO start
     
   first:
     DEBUG 1
     GOTO nextLoop
     
   second:
     DEBUG 2
     GOTO nextLoop
     
   third:
     DEBUG 3
     GOTO nextLoop
