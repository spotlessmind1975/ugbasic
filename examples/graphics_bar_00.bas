REM @english
REM GRAPHICS PRIMITIVES USING BAR (1)
REM
REM This example will draw two red bars.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI BAR (1)
REM
REM Questo esempio disegnerà due barre rosse.

    BITMAP ENABLE(16)
    CLS
    BAR 0,0 TO SCREEN WIDTH / 10, SCREEN HEIGHT / 10
    INK YELLOW
    BAR 0,0 TO (SCREEN WIDTH-1), (SCREEN HEIGHT-1)
    INK RED
    BAR 2 * (SCREEN WIDTH/10), 2*(SCREEN HEIGHT/10) TO _
        (SCREEN WIDTH-1), (SCREEN HEIGHT-1)