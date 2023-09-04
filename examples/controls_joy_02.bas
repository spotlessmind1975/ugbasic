REM @english
REM I/O CONTROL JOYSTICK READ (BIT DECODING)
REM
REM This example will read the joystick status for the first joystick. Then it will decode some
REM values by using the various syntaxes available, and it will represent on the screen.
REM
REM @italian
REM CONTROLLI DI I/O LETTURA JOYSTICK (DECODIFICA BIT)
REM
REM Questo esempio leggerà lo status del primo joystick. Quindi ne decodificherà il valore
REM di alcune direzioni, sfruttando le varie sintassi disponibili, e lo rappresenterà sullo schermo.
REM
REM @include atari,atarixl

   CLS

   HOME

   PRINT "  o  "
   PRINT "o-+-o"
   PRINT "  o  "
   PRINT "====="
   PRINT " JOY "

   DO

      left = BIT( JOY(0), LEFT )
      LOCATE 0, 6: PRINT "LEFT IS: ";left
      
      up = BIT UP OF JOY(0)
      LOCATE 0, 7: PRINT "UP IS  : ";up

      IF JOY(0) HAS BIT UP THEN
         LOCATE 2, 0
         PRINT "*"
      ELSE
         LOCATE 2, 0
         PRINT "o"
      ENDIF

      IF JOY(0) HAS BIT DOWN THEN
         LOCATE 2, 2
         PRINT "*"
      ELSE
         LOCATE 2, 0
         PRINT "o"
      ENDIF

      IF JOY(0) HAS BIT LEFT THEN
         LOCATE 0, 1
         PRINT "*"
      ELSE
         LOCATE 0, 1
         PRINT "o"
      ENDIF

      IF JOY(0) HAS BIT RIGHT THEN
         LOCATE 4, 1
         PRINT "*"
      ELSE
         LOCATE 4, 1
         PRINT "o"
      ENDIF

   LOOP