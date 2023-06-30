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

tileset := LOAD TILESET("kenney-tiny-town.tsx")

class = TILE CLASS( tileset, 29 )
larghezza = TILE WIDTH( tileset )
altezza = TILE HEIGHT( tileset )
probabilita = TILE PROBABILITY( tileset, 29 )

PRINT class;" (" ; larghezza ; "x" ; altezza ; " pixel) % = "; probabilita
