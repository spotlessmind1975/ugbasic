REM @english
REM TILESET SUPPORT RETRIEVING A TILE (MULTILAYER)
REM
REM This example shows how to retrieve the id of a tile at a given position
REM and on first (default) or other layers.
REM
REM @italian
REM GESTIONE DEI TILESET RECUPERO DI UN TILE (MULTILAYER)
REM
REM Questo esempio mostra come si recupera l'identificativo di un tile a una data
REM posizione, sul primo livello (quello di default) e i successivi.
REM
REM @url https://www.mapeditor.org/
REM @url https://kenney.nl/
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000,pc128op,to8,cpc

    BITMAP ENABLE(16)

    CLS

PROCEDURE example ON ALL BUT PLUS4

    tilemap := LOAD TILEMAP("kenney-tiny-town-2layers.tmx") UNBANKED

    PRINT TILEMAP tilemap AT ( 0, 0 )
    PRINT TILEMAP tilemap LAYER 1 AT ( 0, 0 )

END PROC

    example[] ON ALL BUT PLUS4

