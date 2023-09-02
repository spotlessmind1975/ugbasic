REM @english
REM GRAPHICS PRIMITIVES COLORING (USING COLOR)
REM
REM This example will show how to change the color of the index 0,
REM that is normally the background.
REM
REM @italian
REM PRIMITIVE DI GRAFICA COLORAZIONE (USANDO COLOR)
REM
REM Questo esempio mostra come cambiare il colore dell'indice 0,
REM che normalmente è lo sfondo

    BITMAP ENABLE(16)
    CLS BLACK
    DO
        COLOR 0, $555
        COLOR 0, $900
        COLOR 0, $090
        COLOR 0, $009
        COLOR 0, $990
    LOOP