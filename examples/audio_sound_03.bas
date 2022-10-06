REM @english
REM AUDIO GENERATION SOUND SAMPLE (3)
REM
REM This small example will emit a polyphonic sound for 5 seconds.
REM 
REM @italian
REM AUDIO E MUSICA ESEMPIO CON SOUND (3)
REM
REM Questo piccolo esempio emetterà un suono polifonico per cinque secondi.
REM

  SOUND 440 ON %0001
  SOUND 480 ON %0010
  SOUND 480 ON %0010
  FOR i=0 TO 10 : PRINT "OK!": WAIT 500 MS : NEXT
  SOUND OFF
