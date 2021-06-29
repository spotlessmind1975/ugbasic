REM @english
REM GRAPHICS PRIMITIVES DRAWING SHAPES (3)
REM
REM This example will draw random ellipses on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON DISEGNO DI FORME (3)
REM
REM Questo esempio disegnerà ellissi casuali sullo schermo.

    BITMAP ENABLE
    CLS
    x=(POSITION)0
    y=(POSITION)0
    r1=(POSITION)0
    r2=(POSITION)0
    DO
        INK RND(SCREEN COLORS)
        x=RND(SCREEN WIDTH)
        y=RND(SCREEN HEIGHT)
        r1=RND(20)+1
        r2=RND(20)+1
        ELLIPSE x,y,r1,r2
    LOOP
