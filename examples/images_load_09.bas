REM @english
REM STATIC IMAGES MULTIPLE IMAGES LOADING WITH DOUBLE BUFFERING
REM
REM This small example will show how to load and animate images from
REM a single image with all frames, using double buffering (where available).
REM
REM @italian
REM GESTIONE DELLE IMMAGINI CARICAMENTO MULTIPLO CON DOUBLE BUFFERING
REM
REM Questo piccolo esempio mostrerà come caricare e animare un set di immagini 
REM a partire da una immagine singola, con tutti i fotogrammi, usando
REM il double bufferng (dove c'è).
REM

BITMAP ENABLE (16)
DOUBLE BUFFER ON
CLS

bat := LOAD IMAGES("bat.png" ) FRAME SIZE (32,32)

frame = (BYTE) 0

BEGIN GAMELOOP
    PUT IMAGE bat FRAME frame AT 0,0
    ADD frame,1,0 TO FRAMES(bat)-1
END GAMELOOP

