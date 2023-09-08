REM @english
REM GRAPHICS PRIMITIVES DRAWING SHAPES (USING CIRCLE AND POLYLINE)
REM
REM This example will draw a pentacle, using ''CIRCLE'' and ''POLYLINE'' instructions.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON DISEGNO DI FORME (1)
REM
REM Questo esempio disegnerà un pentacolo, utilizzando i comandi ''CIRCLE'' e ''POLYLINE''.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

    BITMAP ENABLE
    CLS
    w = SCREEN WIDTH / 2
    h = SCREEN HEIGHT / 2
    IF SCREEN HEIGHT > SCREEN WIDTH THEN
        d = w/2 
    ELSE
        d = h/2 
    ENDIF
    CIRCLE w,h,d
    POLYLINE w-d,h-d TO w+d,h+d TO w+d,h-d TO w-d,h-d TO w-d,h+d TO w-d,h-d
    