REM @english
REM GRAPHICS PRIMITIVES DRAWING RANDOM CIRCLES
REM
REM This example will draw random circles on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON DISEGNO DI FORME (2)
REM
REM Questo esempio disegnerà cerchi casuali sullo schermo.
REM
REM @include atari,atarixl,c128,c64,coco

    BITMAP ENABLE
    CLS
    INK RED
    w = SCREEN WIDTH / 2
    h = SCREEN HEIGHT / 2
    IF SCREEN HEIGHT > SCREEN WIDTH THEN
        d = w/2 
    ELSE
        d = h/2 
    ENDIF
    GR LOCATE w,h
    CIRCLE ,,d
    x=(POSITION)0
    y=(POSITION)0
    r=(POSITION)0
    DO
        INK RND(SCREEN COLORS)
        x=RND(w)
        y=RND(h)
        r=RND(d)+1
        CIRCLE x,y,r
    LOOP
