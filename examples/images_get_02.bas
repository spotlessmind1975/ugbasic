REM @english
REM STATIC IMAGES MULTICOLOR IMAGE CAPURE (USING GET IMAGE)
REM
REM This small example will show how to capture an image from
REM the screen, to be used then to draw it on another part.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI CATTURA (2)
REM
REM Questo piccolo esempio mostra come catturare una immagine
REM dallo schermo, per essere disegnata su un'altra parte dello schermo.
REM
REM @include atari,atarixl,c128,c64

    BITMAP ENABLE (16)
    CLS

    x = NEW IMAGE(32,32)

    HOME
    PRINT "AAAA"
    PRINT "BBBB"
    PRINT "CCCC"

    GET IMAGE x FROM 0, 0
    PUT IMAGE x AT 0,64