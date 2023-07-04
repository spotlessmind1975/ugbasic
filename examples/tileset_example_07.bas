REM @english
REM TILESET SUPPORT NAMED LOADING
REM
REM This example shows how to load and use a named tiles from tileset 
REM created with a standard tool like "Tiled". The tiles can be indexed
REM by their "class" (type) name. Tileset courtesy of Kenney.
REM
REM For more informations:
REM https://www.mapeditor.org/
REM https://kenney.nl/
REM
REM @italian
REM GESTIONE DEI TILESET CARICAMENTO
REM
REM Questo esempio mostra come si caricano e si utilizzano le tile
REM nominali di un tileset creato con un tool standard come "Tiled".
REM In generale, le tile possono essere indicate anche dal loro
REM nome (il campo "class" o "type"). Il tileset courtesy of Kenney.
REM
REM Per maggiori informazioni:
REM https://www.mapeditor.org/
REM https://kenney.nl/

BITMAP ENABLE(16)

CLS

tilemap := LOAD TILEMAP("kenney-tiny-town-2layers.tmx")

tileset := TILESET(tilemap)

POSITIVE CONST tilesPerColumn = SCREEN HEIGHT / TILE HEIGHT( tileset )
POSITIVE CONST tilesPerRow = SCREEN WIDTH / TILE WIDTH( tileset )
POSITIVE CONST tilesPerRow0 = tilesPerRow-1

slice := NEW IMAGE( 1, SCREEN WIDTH )

DIM map AS BYTE( SCREEN HEIGHT / TILE HEIGHT( tileset ) )

FOR i=0 TO tilesPerColumn - 1
	map(i) = TILEMAP INDEX(tilemap, tilesPerRow0, i)
NEXT

HSCROLL SCREEN LEFT

FOR i=0 TO tilesPerColumn - 1
	t = map(i)
	SLICE IMAGE tileset TILE t _
		WITH (0,0,1,TILE HEIGHT(tileset) AT 0,i*TILE HEIGHT(tileset)) TO slice
NEXT

PUT IMAGE slice AT SCREEN WIDTH - 1, 0

