REM @english
REM GRAPHICS PRIMITIVES USING POINT (1)
REM
REM This example will draw a single pixel at the center of the screen.
REM The color of that pixel will be read using the ''POINT'' function,
REM and it will be printed on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI POINT (1)
REM
REM Questo esempio disegnerà un singolo pixel al centro dello schermo.
REM Il colore di quel pixel sarà letto usando la funzione ''POINT'',
REM e l'indice sarà stampato sullo schermo.

    BITMAP ENABLE
    CLS RED
    INK YELLOW
    PLOT SCREEN WIDTH / 2, SCREEN HEIGHT / 2
    PEN WHITE
    PRINT POINT(SCREEN WIDTH / 2, SCREEN HEIGHT / 2)
    HALT