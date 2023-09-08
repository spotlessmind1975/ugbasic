REM @english
REM GRAPHICS PRIMITIVES POSITIONING (USING GR LOCATE)
REM
REM This example will use the ''GR LOCATE'' command to move the graphical
REM cursor in a specific position. By omitting the coordinates, the command
REM ''CIRCLE'' will draw a circle with the center as the given coordinates.
REM
REM @italian
REM PRIMITIVE DI GRAFICA PER POSIZIONE (1)
REM
REM Questo esempio userà il comando ''GR LOCATE'' per spostare il cursore grafico
REM in una posizione specifica. Omettendo le coordinate, il comando
REM ''CIRCLE'' disegnerà un cerchio con il centro nelle coordinate date.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

    BITMAP ENABLE
    CLS

    x= (POSITION)150
    y= (POSITION)10
    r= (POSITION)0
    
    FOR r=3 TO 87 STEP 3
        GR LOCATE x,y+r
        CIRCLE ,,r
    NEXT
