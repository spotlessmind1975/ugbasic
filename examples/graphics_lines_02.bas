REM @english
REM GRAPHICS PRIMITIVES USING BOX AND PATTERNS (1)
REM
REM This example will draw two red segments.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI BOX E PATTERN (1)
REM
REM Questo esempio disegnerà due segmenti rossi.

    BITMAP ENABLE
    CLS
    INK YELLOW
    SET LINE $f0f0
    BOX 50,100 TO 150,140
    SET LINE %1100110011001100
    BOX 60,110 TO 160,160
    HALT
