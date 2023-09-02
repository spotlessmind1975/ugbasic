
REM @english
REM GRAPHICS PRIMITIVES DRAWING BOXES
REM
REM This example will draw three boxes.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI BOX
REM
REM Questo esempio disegnerà tre rettangoli.
REM
REM @include atari

    BITMAP ENABLE(16)
    CLS
    
    POSITIVE CONST boxWidth = SCREEN WIDTH / 10
    POSITIVE CONST boxHeight = SCREEN HEIGHT / 10

    INK YELLOW
    BOX 0,0 TO boxWidth, boxHeight

    LOCATE 3,5: PRINT "OK 1"

    INK RED
pippero:
    BOX 16,16 TO 16+boxWidth, 16+boxHeight

    LOCATE 3,5: PRINT "OK 2"

    INK GREEN
    BOX 32,32 TO 32+boxWidth, 32+boxHeight

    LOCATE 3,5: PRINT "OK 3"
