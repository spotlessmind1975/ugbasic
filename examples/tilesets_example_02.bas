tileset1 = NEW TILESET
tileset2 = NEW TILESET

tiles = LOAD TILES("examples/drop.png") ROLL X

x = 0

FOR x = 0 TO SCREEN WIDTH
    MOVE TILE tiles AT x, 0
    WAIT 200 MS
NEXT
