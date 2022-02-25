REM @english
REM GRAPHICS PRIMITIVES VERTICAL BLANK SYNC (2)
REM
REM This example will show how to syncronize with the vertical blank using game loops.
REM
REM @italian
REM PRIMITIVE DI GRAFICA SINCRONIZZAZIONE CON IL VERTICAL BLANK (2)
REM
REM Questo esempio mostra come sincronizzarsi con il vertical blank usando i game loop.
REM

    BITMAP ENABLE(16)
    CLS
    BEGIN GAMELOOP
        PLOT RND(SCREEN COLUMNS-1), RND(SCREEN ROWS-1), RND(SCREEN COLORS-1)
    END GAMELOOP