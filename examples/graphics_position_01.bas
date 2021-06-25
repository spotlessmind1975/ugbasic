REM @english
REM GRAPHICS PRIMITIVES USIGN POSITION (1)
REM
REM This example will use the ''GR LOCATE'' command to move the graphical
REM cursor in a specific position. By omitting the coordinates, the command
REM ''CIRCLE'' will draw a circle with the center as the given coordinates.
REM
REM @italian
REM PRIMITIVE DI GRAFICA PER POSIZIONE (1)
REM
REM Questo esempio userà il comando ''GR LOCSATE'' per spostare il cursore grafico
REM in una posizione specifica. Omettendo le coordinate, il comando
REM ''CIRCLE'' disegnerà un cerchio con il centro nelle coordinate date.

    BITMAP ENABLE
    CLS

    CIRCLE 100,100,20,WHITE

    HALT

    x=150
    y=10
    FOR r=3 TO 87 STEP 3
        GR LOCATE x,y+r
        CIRCLE ,,r
    NEXT

    HALT