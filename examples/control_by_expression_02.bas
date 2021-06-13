     times = 1
   start:
     ON times GOSUB first, second, third
     times = times + 1
     IF times > 3 THEN
        times = 1
     ENDIF
     GOTO start
     
   first:
     PRINT 1;" ";
     RETURN
     
   second:
     PRINT 2;" ";
     RETURN
     
   third:
     PRINT 3;" ";
     RETURN