REM @english
REM GRAPHICS PRIMITIVES DRAWING SHAPES (1)
REM
REM This example will draw a pentacle, using ''CIRCLE'' and ''POLYLINE'' instructions.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON DISEGNO DI FORME (1)
REM
REM Questo esempio disegnerà un pentacolo, utilizzando i comandi ''CIRCLE'' e ''POLYLINE''..

    BITMAP ENABLE
    CLS
    CIRCLE 160,100,95
    POLYLINE 160,6 TO 100,173 TO 250,69 TO 71,69 TO 222,173 TO 160,6
    HALT