REM @english
REM TILESET SUPPORT BASIC LOADING
REM
REM This example shows how to load and use a tileset created
REM with a standard tool like "Tiled". Tileset courtesy of Kenney.
REM
REM For more informations:
REM https://www.mapeditor.org/
REM https://kenney.nl/
REM
REM @italian
REM GESTIONE DEI TILESET CARICAMENTO
REM
REM Questo esempio mostra come si carica e si utilizza un
REM tileset creato con un tool standard come "Tiled".
REM Il tileset courtesy of Kenney.
REM
REM Per maggiori informazioni:
REM https://www.mapeditor.org/
REM https://kenney.nl/

BITMAP ENABLE(16)

tileset := LOAD TILESET("kenney-tiny-town.tsx")

PUT IMAGE tileset FRAME 0 AT 0,0


