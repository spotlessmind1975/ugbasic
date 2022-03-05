tileset1 = NEW TILESET
tileset2 = NEW TILESET

tiles = LOAD TILES("examples/drop.png") ROLL Y

y = 0

FOR y = 0 TO SCREEN HEIGHT
    MOVE TILE tiles AT 0, y
    WAIT 100 MS
NEXT
