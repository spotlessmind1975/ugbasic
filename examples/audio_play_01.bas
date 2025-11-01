REM @english
REM AUDIO GENERATION PLAY A NOTE
REM
REM This small example will show how to play a note.
REM 
REM @italian
REM AUDIO E MUSICA SUONARE UNA NOTA
REM
REM Questo piccolo esempio vi mostrerà come suonare una note.
REM

	CLS
	
    PLAY 40, 0 ON 1: PLAY 50, 0 ON 2
    WAIT KEY
    PLAY 50, 15 ON 1: PLAY 50, 15 ON 2
    DO
        v = RND(5)
        p = RND(108)
        PLAY p, 3 ON v
    LOOP

