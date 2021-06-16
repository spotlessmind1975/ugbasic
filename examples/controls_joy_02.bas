REM @english
REM I/O CONTROL WITH JOYSTICK (2)
REM
REM This example will read the joystick status for the first joystick. Then it will decode some
REM values by using the various syntaxes available.
REM
REM @italian
REM CONTROLLI DI I/O CON IL JOYSTICK (2)
REM
REM Questo esempio leggerà lo status del primo joystick. Quindi ne decodificherà il valore
REM di alcune direzioni, sfruttando le varie sintassi disponibili.
REM

   left = BIT( JOY(0), LEFT )
   PRINT "LEFT IS: ";left
   
   up = BIT UP OF JOY(0)
   PRINT "UP IS: ";up

   IF JOY(0) HAS BIT UP THEN : PRINT "UP" : ENDIF
   IF JOY(0) IS UP THEN : PRINT "UP" : ENDIF

   IF JOY(0) HAS NOT BIT UP THEN : PRINT "NOT UP" : ENDIF
   IF JOY(0) IS NOT UP THEN : PRINT "NOT UP" : ENDIF

   HALT