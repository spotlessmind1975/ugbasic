REM @english
REM STATIC IMAGES LOADING (5)
REM
REM This small example will show how to load a real image
REM with a very similar palette.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI CARICAMENTO (5)
REM
REM Questo piccolo esempio mostra come caricare una immagine reale
REM con una palette molto simile.
REM
REM @exclude coleco

SCREEN #0

car = LOAD IMAGE("car.png" )

PUT IMAGE car AT 0, 0

HALT



