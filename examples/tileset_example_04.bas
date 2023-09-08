REM @english
REM TILESET SUPPORT BASIC TILEMAP LOADING (2)
REM
REM This example shows how to load and use a tilemap
REM created with a standard tool like "Tiled". Tileset courtesy 
REM of Kenney.
REM
REM @italian
REM GESTIONE DEI TILESET CARICAMENTO TILEMAP (2)
REM
REM Questo esempio mostra come si caricano e si utilizzano le tilemap
REM create con un tool standard come "Tiled". Il tileset courtesy of Kenney.
REM
REM Per maggiori informazioni:
REM @url https://www.mapeditor.org/
REM @url https://kenney.nl/
REM
REM @include atari,atarixl,c128,c64,coco,coleco,cpc

    BITMAP ENABLE(16)

    CLS

    tilemap := LOAD TILEMAP("kenney-tiny-town-large.tmx")

    PUT TILEMAP tilemap
