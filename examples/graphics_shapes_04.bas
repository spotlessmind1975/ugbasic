REM @english
REM GRAPHICS PRIMITIVES DRAWING SHAPES (4)
REM
REM This example will draw enclosed circles on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON DISEGNO DI FORME (3)
REM
REM Questo esempio disegnerà cerchi concentrici sullo schermo.

    BITMAP ENABLE (160,200,16)
    CLS
    FOR i=0 TO 10
        CIRCLE 80,100,i*10
    NEXT
