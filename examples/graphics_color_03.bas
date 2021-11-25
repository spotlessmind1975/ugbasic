REM @english
REM GRAPHICS PRIMITIVES WHICH SHADE FOR COLOR?
REM
REM This example will show how to show the shades configured
REM by default for each color.
REM
REM @italian
REM PRIMITIVE DI GRAFICA COLORAZIONE DELLO SCHERMO
REM
REM Questo esempio mostra come mostrare le sfumature configurate,
REM per default, per ogni colore.

    BITMAP ENABLE(16)
    CLS BLACK
    INK WHITE
    FOR i = 0 TO SCREEN COLORS - 1
        PRINT "COLOR ";i;" = $";HEX$(COLOR(i))
    NEXT