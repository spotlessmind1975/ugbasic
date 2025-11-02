REM @english
REM AUDIO GENERATION PLAY MUSIC
REM
REM This small example will show how to play a MIDI file.
REM 
REM @italian
REM AUDIO E MUSICA SUONARE MUSICA
REM
REM Questo piccolo esempio vi mostrerà come suonare un file MIDI.
REM

PROCEDURE example ON ALL BUT COCO

	CLS
	
    music := LOAD MUSIC("example.mid")

    MUSIC music

END PROC

    example[] ON ALL BUT COCO
    