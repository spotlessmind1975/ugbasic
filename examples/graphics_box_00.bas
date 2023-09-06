
REM @english
REM GRAPHICS PRIMITIVES DRAWING (COLORED) BOXES
REM
REM This example will draw three boxes, one yellow, one red and one green.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI BOX (COLORATI)
REM
REM Questo esempio disegnerà tre rettangoli: uno giallo, uno rosso e uno verde.
REM
REM @include atari,atarixl,c128,c64,coco

    BITMAP ENABLE(16)
    CLS
    
    POSITIVE CONST boxWidth = SCREEN WIDTH / 10
    POSITIVE CONST boxHeight = SCREEN HEIGHT / 10

    INK YELLOW
    BOX 0,0 TO boxWidth, boxHeight

    INK RED
    BOX 16,16 TO 16+boxWidth, 16+boxHeight

    INK GREEN
    BOX 32,32 TO 32+boxWidth, 32+boxHeight
