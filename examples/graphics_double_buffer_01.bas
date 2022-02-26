REM @english
REM GRAPHICS PRIMITIVES USING DOUBLE BUFFER
REM
REM This example will show how to use the double buffering.
REM
REM @italian
REM PRIMITIVE DI GRAFICA USARE IL DOUBLE BUFFERING
REM
REM Questo esempio mostra come usare il double buffering.
REM

    SCREEN #3
    CLS BLACK
    DOUBLE BUFFER ON
    CLS BLACK
    x1 = 0
    y1 = 0
    x2 = 100
    y2 = 100
    BEGIN GAMELOOP
        DRAW x1, y1 TO x2, y2, BLACK
        x1 = RND(( SCREEN WIDTH-1 ) \ #2)
        y1 = RND(( SCREEN HEIGHT-1 ) \ #2)
        x2 = x1 + RND(( SCREEN WIDTH-1 ) \ #2)
        y2 = y1 + RND(( SCREEN WIDTH-1 ) \ #2)
        DRAW x1, y1 TO x2, y2, WHITE
    END GAMELOOP