REM @english
REM AUDIO GENERATION PLAY THE BELL
REM
REM This small example will emit a bell-like sound. Take note
REM that, since ugBASIC is an insomorphic language, the actual
REM range of values for BELL will change accordingly with the
REM target choosen. We use conditional compilation to show
REM how to differentiate the BELL usage.
REM 
REM @italian
REM AUDIO E MUSICA SUONARE IL CAMPANELLO
REM
REM Questo piccolo esempio emetterà un suono simile a quello
REM di una campana. Si noti che, poiché ugBASIC è un 
REM linguaggio insomorfo, l'intervallo effettivo di valori 
REM per BELL cambierà in base al target scelto. Utilizziamo 
REM la compilazione condizionale per mostrare come 
REM differenziare l'utilizzo di BELL.
REM
REM @target atari,atarixl,c128,

PROCEDURE example ON POKEY, TED

    FOR f=0 TO 107
        PRINT "BELL ";f
        BELL f
        WAIT 1000 MS
    NEXT

END PROCEDURE

PROCEDURE example ON SID

    FOR f=67 TO 107
        PRINT "BELL ";f
        BELL f
        WAIT 1000 MS
    NEXT

END PROCEDURE

    CLS

	example[] ON POKEY, TED, SID
	