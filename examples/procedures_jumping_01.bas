    PROCEDURE first
        PRINT 1;" ";
    END PROC
     
    PROCEDURE second
        PRINT 2;" ";
    END PROC
     
    PROCEDURE third
        PRINT 3;" ";
    END PROC

   times = 1
   start:
     ON times PROC first, second, third
     times = times + 1
     IF times > 3 THEN
        times = 1
     ENDIF
     GOTO start
     
