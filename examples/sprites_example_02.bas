REM @english
REM SPRITE MANAGEMENT MOVING PARALLEL SPRITES
REM
REM This example shows how to move sprites by using the multitasking
REM feature, assigning a movement routine to each sprite.
REM
REM @italian
REM GESTIONE DEGLI SPRITE MUOVERE SPRITE IN PARALLELO
REM
REM Questo esempio mostra come muovere gli sprite usando la feature
REM del multitasking, assegnando quindi una routine di movimento
REM per ogni sprite.

BITMAP ENABLE (2)

DEFINE TASK COUNT SPRITE COUNT 

DIM sprites AS SPRITE (SPRITE COUNT)
DIM x AS POSITION (SPRITE COUNT)
DIM y AS POSITION (SPRITE COUNT)

spriteImage = IMAGE LOAD("examples/drop.png")

GLOBAL sprites,x,y,spriteImage

PARALLEL PROCEDURE dropDown
    SPRITE [sprites] ENABLE
    DO
        [x] = RANDOM WIDTH
        FOR [y] = 0 TO SCREEN HEIGHT + IMAGE HEIGHT(spriteImage)
            SPRITE [sprites] AT [x], [y] COLOR BLUE
        NEXT
    LOOP
END PROC    

drops = 0
dropskip = (BYTE) ( SPRITE HEIGHT * 2 )

FOR i=0 TO SPRITE COUNT -1
    sprites(i) = SPRITE(spriteImage)
NEXT

SPAWN dropDown

DO
    IF drops < (SPRITE COUNT-1) THEN
        DEC dropskip
        IF dropskip = 0 THEN
            SPAWN dropDown
            dropskip = SPRITE HEIGHT
            INC drops
        ENDIF
    ENDIF
    RUN PARALLEL
LOOP

