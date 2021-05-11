     times = 1
   start:
     ON times PROC first, second, third
     times = times + 1
     IF times > 3 THEN
        times = 1
     ENDIF
     GOTO start
     
    PROCEDURE first
        DEBUG 1
    END PROC
     
    PROCEDURE second
        DEBUG 2
    END PROC
     
    PROCEDURE third
        DEBUG 3
    END PROC