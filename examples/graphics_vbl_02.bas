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
REM @include atari,atarixl,c128

    BITMAP ENABLE(16)
    CLS
    BEGIN GAMELOOP
        SELECT CASE RND(SCREEN COLORS-1)
            CASE 0
                c = WHITE
            CASE 1
                c = RED
            CASE 2
                c = BLUE
            CASE 3
                c = GREEN
            CASE ELSE
                c = YELLOW
        ENDSELECT
        PEN c    
        PLOT RND(SCREEN COLUMNS-1), RND(SCREEN ROWS-1)
    END GAMELOOP