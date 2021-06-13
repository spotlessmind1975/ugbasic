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
     PRINT 1;" ";
     GOTO nextLoop
     
   second:
     PRINT 2;" ";
     GOTO nextLoop
     
   third:
     PRINT 3;" ";
     GOTO nextLoop
