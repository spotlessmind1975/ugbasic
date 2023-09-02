REM @english
REM GRAPHICS PRIMITIVES DRAWING RANDOM TEXTS
REM
REM This example will print random colorized strings on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA USANDO I COMANDI PEN, PAPER E LOCATE
REM
REM Questo esempio stamperà stringhe di colore casuale sullo schermo.
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
        LOCATE RND(SCREEN COLUMNS-1), RND(SCREEN ROWS-1)
        PRINT "ugBASIC!";
        PRINT RND(SCREEN ROWS-1);" "
    LOOP