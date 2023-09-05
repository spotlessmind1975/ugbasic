REM @english
REM STATIC IMAGES LOADING FLIPPED IMAGE (USING FLIP X)
REM
REM This small example will show how to load and flip a PNG image.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI DISEGNO (2)
REM
REM Questo piccolo esempio mostra come caricare una piccola PNG e disegnarla sulla bitmap colorata.
REM
REM @include atari,atarixl,c128


    BITMAP ENABLE (16)

    CLS

    airplane1 := LOAD IMAGE("air_attack_airplane.png")
    airplane2 := LOAD IMAGE("air_attack_airplane.png" AS "airplanef") FLIP X

    PUT IMAGE airplane1 AT 0,0
    PUT IMAGE airplane2 AT 16,16

