REM @english
REM GRAPHICS PRIMITIVES COLORING (USING INK)
REM
REM This example will show the effect of the use of ''INK'' command.
REM
REM @italian
REM PRIMITIVE DI GRAFICA COLORAZIONE (USANDO INK)
REM
REM Questo esempio mostra l'effetto dell'utilizzo del comando ''INK''.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

    BITMAP ENABLE
    CLS

    COLOR BACK RED
    INK YELLOW
    DRAW TO 319,199
