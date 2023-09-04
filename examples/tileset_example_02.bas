REM @english
REM TILESET SUPPORT TILE PROPERTIES
REM
REM This example shows how to load and use a named tiles from tileset 
REM created with a standard tool like "Tiled". The tiles can be indexed
REM by their "class" (type) name. Tileset courtesy of Kenney.
REM
REM @italian
REM GESTIONE DEI TILESET PROPRIETA DEI TILE
REM
REM Questo esempio mostra come si caricano e si utilizzano le tile
REM nominali di un tileset creato con un tool standard come "Tiled".
REM In generale, le tile possono essere indicate anche dal loro
REM nome (il campo "class" o "type"). Il tileset courtesy of Kenney.
REM
REM @url https://www.mapeditor.org/
REM @url https://kenney.nl/
REM
REM @include atari

	BITMAP ENABLE(16)

	CLS

	tileset := LOAD TILESET("kenney-tiny-town.tsx")

	classe = TILE CLASS( tileset, 29 )
	larghezza = TILE WIDTH( tileset )
	altezza = TILE HEIGHT( tileset )
	probabilita = TILE PROBABILITY( tileset, 29 )

	FOR i = 0 TO 8
		PUT IMAGE tileset TILE 29 AT 16*i, 32
	NEXT

	PRINT classe;" (" ; larghezza ; "x" ; altezza ; " px)"
	PRINT " % = "; probabilita




