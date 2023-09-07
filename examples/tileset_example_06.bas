REM @english
REM TILESET SUPPORT USING MULTILAYERS TILEMAP
REM
REM This example shows how to load and use a multilayer tilemap
REM created with a standard tool like "Tiled". Tileset courtesy 
REM of Kenney.
REM
REM @italian
REM GESTIONE DEI TILESET TILEMAP MULTILAYER
REM
REM Questo esempio mostra come si caricano e si utilizzano le tilemap multilayer
REM create con un tool standard come "Tiled". Il tileset courtesy of Kenney.
REM
REM @url https://www.mapeditor.org/
REM @url https://kenney.nl/
REM
REM @include atari,atarixl,c128,c64,coco,coleco

    BITMAP ENABLE(16)

    CLS

    tilemap := LOAD TILEMAP("kenney-tiny-town-2layers.tmx")

    PUT TILEMAP tilemap
