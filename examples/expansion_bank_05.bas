REM @english
REM EXPANSION MANAGEMENT LOAD IMAGES ON BANK
REM
REM This example shows how to load images on an expansion.
REM
REM @italian
REM ESPANSIONE DI MEMORIA CARICARE IMMAGINI NELL'ESPANSIONE
REM
REM Questo esempio mostra come caricare le immagini su una espansione.

BITMAP ENABLE (16)

bat := LOAD IMAGES("bat.png" ) FRAME SIZE (32,32) BANKED

DO
    PUT IMAGE bat FRAME frame AT 0,0
    ADD frame,1,0 TO FRAMES(bat)-1
LOOP

HALT