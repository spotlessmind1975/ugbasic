REM @english
REM STATIC IMAGES MULTIPLE IMAGES LOADING (2)
REM
REM This small example will show how to load and animate images from
REM a single image with all frames.
REM
REM @italian
REM GESTIONE DELLE IMMAGINI CARICAMENTO MULTIPLO (2)
REM
REM Questo piccolo esempio mostrerà come caricare e animare un set di immagini 
REM a partire da una immagine singola, con tutti i fotogrammi.
REM

BITMAP ENABLE (16)
CLS

bat := IMAGES LOAD("examples/bat.png" ) FRAME SIZE (32,32)

frame = (BYTE) 0

DO
    PUT IMAGE bat FRAME frame AT 0,0
    ADD frame,1,0 TO FRAMES(bat)-1
LOOP

