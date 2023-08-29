REM @english
REM TILESET SUPPORT SCROLLING TILEMAP
REM
REM This example shows how to scroll a tilemap created with a standard tool 
REM like "Tiled". Tileset courtesy of Kenney.
REM
REM For more informations:
REM https://www.mapeditor.org/
REM https://kenney.nl/
REM
REM @italian
REM GESTIONE DEI TILESET SCORRIMENTO DI UNA TILEMAP
REM
REM Questo esempio mostra come scorrere una tilemap creata 
REM con un tool standard come "Tiled". Il tileset courtesy of Kenney.
REM
REM Per maggiori informazioni:
REM https://www.mapeditor.org/
REM https://kenney.nl/

BITMAP ENABLE(16)

CLS

tilemap := LOAD TILEMAP("kenney-tiny-town-large.tmx")

FOR x = 0 TO TILEMAP WIDTH(tilemap)-1
	PUT TILEMAP tilemap FROM x, 1
	WAIT KEY
NEXT





