REM @english
REM AUDIO GENERATION SOUND SAMPLE (2)
REM
REM This small example will emit a monotone sound for 5 seconds.
REM 
REM @italian
REM AUDIO E MUSICA ESEMPIO CON SOUND (2)
REM
REM Questo piccolo esempio emetterà un suono monotono per cinque secondi.
REM

	CLS

    SOUND 440
    FOR i=0 TO 10 : PRINT "OK!": WAIT 500 MS : NEXT
    SOUND OFF

