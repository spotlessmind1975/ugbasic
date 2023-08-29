REM @english
REM TILESET SUPPORT USING TILEMAP
REM
REM This example shows how to load and use a tilemap created
REM with a standard tool like "Tiled". Tileset courtesy of Kenney.
REM
REM For more informations:
REM https://www.mapeditor.org/
REM https://kenney.nl/
REM
REM @italian
REM GESTIONE DEI TILESET CARICAMENTO DI UN TILEMAP
REM
REM Questo esempio mostra come si carica e si utilizza una
REM tilemap creato con un tool standard come "Tiled".
REM Il tileset courtesy of Kenney.
REM
REM Per maggiori informazioni:
REM https://www.mapeditor.org/
REM https://kenney.nl/

BITMAP ENABLE(16)

tilemap := LOAD TILEMAP("kenney-tiny-town.tmx")

PUT TILEMAP tilemap
