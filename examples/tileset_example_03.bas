REM @english
REM TILESET SUPPORT BASIC TILEMAP LOADING (1)
REM
REM This example shows how to load and use a tilemap
REM created with a standard tool like "Tiled". Tileset courtesy 
REM of Kenney.
REM
REM For more informations:
REM https://www.mapeditor.org/
REM https://kenney.nl/
REM
REM @italian
REM GESTIONE DEI TILESET CARICAMENTO TILEMAP (1)
REM
REM Questo esempio mostra come si caricano e si utilizzano le tilemap
REM create con un tool standard come "Tiled". Il tileset courtesy of Kenney.
REM
REM Per maggiori informazioni:
REM https://www.mapeditor.org/
REM https://kenney.nl/

BITMAP ENABLE(16)

CLS

tilemap := LOAD TILEMAP("kenney-tiny-town.tmx")

PUT TILEMAP tilemap



