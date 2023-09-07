REM @english
REM GRAPHICS PRIMITIVES CLIPPING DRAWING
REM
REM This example will show the effect of the use of ''CLIP'' command.
REM
REM @italian
REM PRIMITIVE DI GRAFICA DISEGNARE CON IL CLIPPING
REM
REM Questo esempio mostra l'effetto dell'utilizzo del comando ''CLIP''.
REM
REM @include atari,atarixl,c128,c64,coco,coleco

    BITMAP ENABLE
    CLS BLACK

    INK YELLOW
    CLIP 20,20 TO 50,50

    r = (POSITION) 0
    FOR r=4 TO 96 STEP 4
        GR LOCATE 10, r
        CIRCLE ,,r+9
    NEXT
