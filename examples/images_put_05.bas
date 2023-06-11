REM @english
REM STATIC IMAGES FLIPPING HORIZONTAL
REM
REM This small example will show how to load and flip an image.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI INVERSIONE ORIZZONTALE
REM
REM Questo piccolo esempio mostra come caricare una immagine invertendola orizzontalmente.
REM

BITMAP ENABLE (16)

CLS

airplane1 := LOAD IMAGE("air_attack_airplane.png")
airplane2 := LOAD IMAGE("air_attack_airplane.png" AS "airplanef") FLIP X

PUT IMAGE airplane1 AT 0,0
PUT IMAGE airplane2 AT 16,16

HALT
