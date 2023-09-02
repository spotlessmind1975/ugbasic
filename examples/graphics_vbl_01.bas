REM @english
REM GRAPHICS PRIMITIVES VERTICAL BLANK SYNC (1)
REM
REM This example will show how to programmatically syncronize with the vertical blank.
REM
REM @italian
REM PRIMITIVE DI GRAFICA SINCRONIZZAZIONE CON IL VERTICAL BLANK (1)
REM
REM Questo esempio mostra come sincronizzarsi, programmaticamente, con il vertical blank.
REM
REM @include atari

    BITMAP ENABLE(16)
    CLS
    DO
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
        WAIT VBL
    LOOP