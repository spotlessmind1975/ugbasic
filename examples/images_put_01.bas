REM @english
REM STATIC IMAGES DRAWING (1)
REM
REM This small example will show how to load and draw a PNG image on a bitmap screen.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI DISEGNO (1)
REM
REM Questo piccolo esempio mostra come caricare una piccola PNG e disegnarla sulla bitmap.
REM

BITMAP ENABLE

CLS

airplane = IMAGE LOAD("examples/air_attack_airplane.png")

PUT IMAGE airplane AT 0,0
PUT IMAGE airplane AT 16,16
PUT IMAGE airplane AT 32,32

HALT
