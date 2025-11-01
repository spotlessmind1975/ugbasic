﻿REM @english
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
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,pc128op,to8,cpc

OPTION COMPILE ON ALL BUT GB

	BITMAP ENABLE(16)

	CLS

PROCEDURE example ON ALL BUT PLUS4, C16

	tileset := LOAD TILESET("kenney-tiny-town.tsx") UNBANKED

	classe = TILE CLASS( tileset, TILE ID( tileset, mushroom ) )
	larghezza = TILE WIDTH( tileset )
	altezza = TILE HEIGHT( tileset )
	probabilita = TILE PROBABILITY( tileset, 29 )

	FOR i = 0 TO 8
		PUT IMAGE tileset TILE 29 AT 16*i, 32
	NEXT

	PRINT classe;" (" ; larghezza ; "x" ; altezza ; " px)"
	PRINT " % = "; probabilita

END PROC

example[] ON ALL BUT PLUS4, C16

