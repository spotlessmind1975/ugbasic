REM @english
REM STATIC IMAGES MONOCHROME IMAGE CAPURE (USING GET IMAGE)
REM
REM This small example will show how to capture an image from
REM the screen, to be used then to draw it on another part.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI CATTURA (1)
REM
REM Questo piccolo esempio mostra come catturare una immagine
REM dallo schermo, per essere disegnata su un'altra parte dello schermo.
REM
REM @include atari,atarixl,c128,c64,coco,coleco

    BITMAP ENABLE (2)
    CLS

    x = NEW IMAGE(32,32)

    HOME
    PRINT "1234"
    PRINT "ABCD"
    PRINT "abcd"

    GET IMAGE x FROM 0, 0
    PUT IMAGE x AT 0,32
