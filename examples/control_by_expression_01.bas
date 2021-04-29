     times = 1
   start:
     ON times GOSUB first, second, third
     times = times + 1
     IF times > 3 THEN
        times = 1
     ENDIF
     GOTO start
     
   first:
     DEBUG 1
     RETURN
     
   second:
     DEBUG 2
     RETURN
     
   third:
     DEBUG 3
     RETURN