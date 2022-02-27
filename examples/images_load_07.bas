REM @english
REM STATIC IMAGES LOADING (4)
REM
REM This small example will show how to load a real image.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI CARICAMENTO (4)
REM
REM Questo piccolo esempio mostra come caricare una immagine reale.
REM
REM @exclude coleco

SCREEN #0

car = LOAD IMAGE("examples/car.png" )

PUT IMAGE car AT 0, 0

HALT



