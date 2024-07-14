REM @english
REM I/O CONTROL ANALOGIC JOYSTICK READ (FUNCTIONS)
REM
REM This example will give back the actual value of analogic
REM joystick, along the horizontal and vertical directions.
REM
REM @italian
REM CONTROLLI DI I/O LETTURA JOYSTICK ANALOGICO (FUNZIONI)
REM
REM Questo esempio restituirà il valore attuale dei joystick
REM analogici, lungo le direzioni orizzontali e verticali.
REM
REM @include coco coco3 d32 d64

   CLS

   DO
   		HOME
   		CLINE : PRINT "HZ = ";JOY X(0);" ";JLEFT(0)
   		CLINE : PRINT "VT = ";JOY Y(0);" ";JUP(0)
   LOOP

