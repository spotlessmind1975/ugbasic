REM @english
REM EXPANSION MANAGEMENT LOAD IMAGE ON BANK
REM
REM This example shows how to load an image on an expansion.
REM
REM @italian
REM ESPANSIONE DI MEMORIA CARICARE UNA IMMAGINE NELL'ESPANSIONE
REM
REM Questo esempio mostra come caricare una immagine su una espansione.

BITMAP ENABLE (2)

eye := LOAD IMAGE("examples/checkers2.png" )

PUT IMAGE eye AT 0, 0

HALT