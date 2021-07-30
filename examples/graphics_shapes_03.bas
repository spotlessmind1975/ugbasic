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
    w = SCREEN WIDTH / 2
    h = SCREEN HEIGHT / 2
    IF SCREEN HEIGHT > SCREEN WIDTH THEN
        d = w/10
    ELSE
        d = h/10
    ENDIF

    x=(POSITION)0
    y=(POSITION)0
    r1=(POSITION)0
    r2=(POSITION)0
    DO
        INK RND(SCREEN COLORS)
        x=RND(w)
        y=RND(h)
        r1=2: REM RND(d)+1
        r2=8: REM RND(d)+1
        ELLIPSE x,y,r1,r2
    LOOP
