REM @english
REM AUDIO GENERATION USE INSTRUMENTS
REM
REM This small example will show how to use instruments.
REM 
REM @italian
REM AUDIO E MUSICA USARE GLI STRUMENTI
REM
REM Questo piccolo esempio vi mostrerà come usare gli strumenti
REM

	CLS

    INSTRUMENT ACOUSTIC GRAND PIANO ON 1
    INSTRUMENT REED ORGAN ON 2

    PLAY 60, 0 ON 1: PLAY 63, 0 ON 2
    WAIT KEY
    PLAY 60, 100 ON 1: PLAY 64, 100 ON 2
    DO
        p = RND(10)
        PLAY 60+p, 200 ON 3
    LOOP

