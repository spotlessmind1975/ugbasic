REM @english
REM STATIC IMAGES LOADING IMAGE ( USING PRINT )
REM
REM This small example will show how to load a PNG image file as a static ''IMAGE''.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI CARICAMENTO (1)
REM
REM Questo piccolo esempio mostra come caricare una piccola PNG come immagine statica.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

    BITMAP ENABLE
    CLS

    airplane = LOAD IMAGE("air_attack_airplane.png")

    PRINT airplane
