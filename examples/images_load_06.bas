REM @english
REM STATIC IMAGES DISPLAY ANIMATIONS
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
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

    BITMAP ENABLE (16)
    CLS

    boy := LOAD ATLAS("boy.png" ) FRAME SIZE (32,32)

    frame = 0

    DO
        PUT IMAGE boy FRAME frame AT 0,0
        ADD frame,1,0 TO FRAMES(boy)-1
    LOOP

