REM @english
REM STATIC IMAGES DISPLAY MONOCHROME IMAGE (USING PUT IMAGE)
REM
REM This small example will show how to load and draw a PNG image on a bitmap screen.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI DISEGNO (1)
REM
REM Questo piccolo esempio mostra come caricare una piccola PNG e disegnarla sulla bitmap.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

    BITMAP ENABLE (2)

    CLS

    airplane = LOAD IMAGE("air_attack_airplane.png")

    PUT IMAGE airplane AT 0,0
    PUT IMAGE airplane AT 16,16
    PUT IMAGE airplane AT 32,32
