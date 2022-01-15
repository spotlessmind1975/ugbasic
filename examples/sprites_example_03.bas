REM @english
REM SPRITE MANAGEMENT MOVING PARALLEL SPRITES IN GAMELOOP
REM
REM This example shows how to move sprites by using the multitasking
REM feature, assigning a movement routine to each sprite, and inside
REM a game loop, to improve performances on VBL constaint systems.
REM
REM @italian
REM GESTIONE DEGLI SPRITE MUOVERE SPRITE IN PARALLELO IN UN GAME LOOP
REM
REM Questo esempio mostra come muovere gli sprite usando la feature
REM del multitasking, assegnando quindi una routine di movimento
REM per ogni sprite, e all'interno di un "game loop", per migliorare
REM le performance sui sistemi che sono vincolati al vertical blank.

BITMAP ENABLE (2)

CONST spriteCount = IF(SPRITE COUNT>0,SPRITE COUNT,16)

DEFINE TASK COUNT spriteCount

DIM sprites AS SPRITE (spriteCount)
DIM x AS POSITION (spriteCount)
DIM y AS POSITION (spriteCount)

spriteImage = IMAGE LOAD("examples/drop.png")

GLOBAL sprites,x,y,spriteImage

drops = 0
dropskip = (BYTE) ( SPRITE HEIGHT * 2 )

FOR i=0 TO spriteCount-1
    sprites(i) = SPRITE(spriteImage)
NEXT

BEGIN GAMELOOP

    PARALLEL PROCEDURE dropDown
        SPRITE [sprites] ENABLE
        DO
            [x] = RANDOM WIDTH
            FOR [y] = 0 TO SCREEN HEIGHT + IMAGE HEIGHT(spriteImage)
                SPRITE [sprites] AT [x], [y] COLOR BLUE
            NEXT
        LOOP
    END PROC    

    IF drops < (spriteCount-1) THEN
        DEC dropskip
        IF dropskip = 0 THEN
            SPAWN dropDown
            dropskip = SPRITE HEIGHT
            INC drops
        ENDIF
    ENDIF

END GAMELOOP