REM @english
REM STATIC IMAGES DISPLAY MULTICOLOR IMAGE (USING PUT IMAGE)
REM
REM This small example will show how to load and draw a PNG image on a colored bitmap screen.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI DISEGNO (2)
REM
REM Questo piccolo esempio mostra come caricare una piccola PNG e disegnarla sulla bitmap colorata.
REM
REM @include atari,atarixl,c128,c64

    BITMAP ENABLE (16)

    CLS

    airplane = LOAD IMAGE("air_attack_airplane.png")

    PUT IMAGE airplane AT 0,0
    PUT IMAGE airplane AT 16,16
    PUT IMAGE airplane AT 32,32
