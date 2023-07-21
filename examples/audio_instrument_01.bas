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

    INSTRUMENT XYLOPHONE ON 1
    INSTRUMENT HARPSICHORD ON 2

    PLAY 40, 0 ON 1: PLAY 50, 0 ON 2
    WAIT KEY
    PLAY 50, 15 ON 1: PLAY 50, 15 ON 2
    DO
        v = RND(5)
        p = RND(108)
        PLAY p, 3 ON v
    LOOP

