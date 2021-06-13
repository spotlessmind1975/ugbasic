  PROCEDURE escape
     FOR prison = 1 TO 1000000000
        IF prison == 10 THEN : POP PROC : ENDIF
        PRINT "I AM ABANDONED.";" ";
     NEXT
  END PROC
  
  escape
  
  PRINT "I AM FREE!";" ";

  HALT