REM @english
REM GRAPHICS PRIMITIVES USING PEN, PAPER AND LOCATE
REM
REM This example will print random colorized strings on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA USANDO I COMANDI PEN, PAPER E LOCATE
REM
REM Questo esempio stamperà stringhe di colore casuale sullo schermo.
REM
REM @exclude coleco

    BITMAP ENABLE(16)
    CLS
    DO
        PEN RND(SCREEN COLORS-1)
        LOCATE RND(SCREEN COLUMNS-1), RND(SCREEN ROWS-1)
        PRINT "ugBASIC!";
        PRINT RND(SCREEN ROWS-1);" "
    LOOP