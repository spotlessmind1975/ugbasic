REM @english
REM I/O CONTROL WITH JOYSTICK (3)
REM
REM This example will run an endless loop (''DO...LOOP'') to read the status
REM of the first joystick. The various directions will be decoded by using
REM the various functions (''JLEFT'', ''JRIGHT'', ''JUP'', ''JDOWN'', ''JFIRE'').
REM
REM @italian
REM CONTROLLI DI I/O CON IL JOYSTICK (3)
REM
REM Questo esempio eseguirà un loop senza fine (''DO...LOOP'') per leggere lo stato
REM del primo joystick. Le varie direzioni saranno decodificate utilizzando
REM le varie funzioni specifiche (''JLEFT'', ''JRIGHT'', ''JUP'', ''JDOWN'', ''JFIRE'').
REM

   DO
      IF JLEFT(0) THEN : PRINT "WEST" : ENDIF
      IF JRIGHT(0) THEN : PRINT "EAST" : ENDIF
      IF JUP(0) THEN : PRINT "NORTH" : ENDIF
      IF JDOWN(0) THEN : PRINT "SOUTH" : ENDIF
      IF JFIRE(0) THEN : CENTRE "BANG!" : ENDIF
   LOOP
