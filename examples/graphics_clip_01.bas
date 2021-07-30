REM @english
REM GRAPHICS PRIMITIVES WITH CLIPPING (1)
REM
REM This example will show the effect of the use of ''CLIP'' command.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON CLIPPING (1)
REM
REM Questo esempio mostra l'effetto dell'utilizzo del comando ''CLIP''.

    BITMAP ENABLE
    CLS BLACK
    CLIP 20,20 TO 50,50
    r = (POSITION) 0
    FOR r=4 TO 96 STEP 4
        GR LOCATE 10, r
        CIRCLE ,,r+9
    NEXT

    HALT
