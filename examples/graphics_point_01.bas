REM @english
REM GRAPHICS PRIMITIVES COLOR AT POINT
REM
REM This example will use the ''POINT'' function to retrieve the color
REM at the given position on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA PER POSIZIONE (1)
REM
REM Questo esempio utilizzerà la funzione ''POINT'' per recuperare il 
REM colore nella posizione specificata sullo schermo.
REM
REM @include 

    BITMAP ENABLE(16)

    CLS

    PLOT 0, 0, WHITE
    PLOT 1, 1, WHITE
    PLOT 2, 2, WHITE
    PLOT 3, 3, WHITE

    c1 = POINT(0,0)
    c2 = POINT(1,1)
    c3 = POINT(2,2)
    c4 = POINT(3,3)

    IF ( c1 = WHITE ) AND ( c2 = WHITE ) AND ( c3 = WHITE ) AND ( c4 = WHITE ) THEN
        PRINT "OK!"
    ELSE
        PRINT "KO!"
        PRINT HEX(c1)
        PRINT HEX(c2)
        PRINT HEX(c3)
        PRINT HEX(c4)
    ENDIF