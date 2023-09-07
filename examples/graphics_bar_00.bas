REM @english
REM GRAPHICS PRIMITIVES DRAWING BARS (PEDESTRIAN CROSSING)
REM
REM This example will draw a pedestrian crossing.
REM
REM @italian
REM PRIMITIVE DI GRAFICA DISEGNARE BARRE (STRISCE PEDONALI)
REM
REM Questo esempio disegnerà delle strisce pedonali.
REM
REM @include atari,atarixl,c128,c64,coleco

    BITMAP ENABLE(2)
    
    CLS

    POSITIVE CONST barWidth = SCREEN WIDTH / 10
    POSITIVE CONST barSpacing = SCREEN WIDTH / 5

    FOR i=0 TO SCREEN WIDTH STEP barSpacing

        INK WHITE
        BAR i,0 TO i + barWidth, SCREEN HEIGHT - 1

    NEXT