  PROCEDURE escape
     FOR prison = 1 TO 1000000000
        IF prison == 10 THEN : POP PROC : ENDIF
        DEBUG "I AM ABANDONED."
     NEXT
  END PROC
  
  escape
  
  DEBUG "I AM FREE!"

  HALT