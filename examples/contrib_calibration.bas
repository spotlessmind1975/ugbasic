REM @english
REM OTHER CONTRIBUTIONS TIME CALIBRATION
REM
REM This source is intended to verify how the implementation of the 
REM TIMER variable (TI) accurately measures time. For this purpose, 
REM it can be used to calibrate the passage of exactly 10 seconds.
REM As added value, this source code explain how to detect if the
REM computer is running under PAL or NTSC frequecy.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI CALIBRAZIONE DEL TEMPO
REM
REM Questo sorgente ha lo scopo di verificare come l'implementazione 
REM della variabile TIMER (TI) misuri con esattezza il tempo. A 
REM tale scopo, lo si potrà utilizzare per calibrare il trascorrere 
REM di 10 secondi esatti. Come valore aggiunto, questo codice sorgente
REM spiega come rilevare se il computer sta funzionando in PAL
REM oppure in NTSC.
REM
REM @include atari,atarixl,c128

CLS BLACK

INK WHITE

PRINT "HARDWARE DETECTED: ";

IF TICKS PER SECOND = 50 THEN
	PRINT "PAL (50 Hz)"
ELSE
	PRINT "NTSC (60 Hz)"
ENDIF

PRINT 

PRINT "10 SECS -> ";

DIM s AS BYTE = 0
DIM t AS INTEGER = 0
DIM dt AS INTEGER = 0

DO
	t = TIMER

	WHILE ( TIMER - t ) < TICKS PER SECOND
		
		LOCATE 11 + s, 2

		dt = TIMER - t
		
		IF dt = 0 THEN
			PRINT ".";
		ELSEIF dt = ( TICKS PER SECOND / 4 ) THEN
			PRINT " ";
		ELSEIF dt = ( ( 2 * TICKS PER SECOND ) / 4 ) THEN
			PRINT ".";
		ELSEIF dt = ( ( 3 * TICKS PER SECOND ) / 4 ) THEN
			PRINT " ";
		ENDIF

	WEND
	
	LOCATE 11 + s, 2
	PRINT "*";
	
	INC s
	
	EXIT IF s = 10
	
LOOP

PRINT " (elapsed)"

