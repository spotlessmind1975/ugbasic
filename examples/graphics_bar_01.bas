REM @english
REM GRAPHICS PRIMITIVES DRAWING BARS (TWO RED BARS)
REM
REM This example will draw two red bars.
REM
REM @italian
REM PRIMITIVE DI GRAFICA DISEGNARE BARRE (DUE BARRE ROSSE)
REM
REM Questo esempio disegnerà due barre rosse.
REM
REM @include atari,atarixl,c128,c64,coco,coleco

    BITMAP ENABLE(16)

    CLS
    BAR 0,0 TO 20,SCREEN HEIGHT-1, RED
    BAR 40,0 TO 60,SCREEN HEIGHT-1, RED
