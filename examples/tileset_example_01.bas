REM @english
REM TILESET SUPPORT BASIC USAGE
REM
REM This example shows how to load and use a tileset created
REM with a standard tool like "Tiled". Tileset courtesy of Kenney.
REM
REM @italian
REM GESTIONE DEI TILESET USO DI BASE
REM
REM Questo esempio mostra come si carica e si utilizza un
REM tileset creato con un tool standard come "Tiled".
REM Il tileset courtesy of Kenney.
REM
REM @url https://www.mapeditor.org/
REM @url https://kenney.nl/
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

    BITMAP ENABLE(16)

    CLS

    tileset := LOAD TILESET("kenney-tiny-town.tsx")

    PUT IMAGE tileset FRAME 29 AT 0,0




