REM @english
REM GRAPHICS PRIMITIVES USING PALETTE
REM
REM This example will show how to use the PALETTE command.
REM
REM @italian
REM PRIMITIVE DI GRAFICA USANDO LA PALETTE
REM
REM Questo esempio mostra come usare il comando PALETTE.

    BITMAP ENABLE(320,200,16)
    PALETTE RGB(0,0,0),RGB(255,0,0),RGB(0,255,0),RGB(0,0,255)
    CLS
    CONST w = SCREEN WIDTH / 3
    CONST h = SCREEN HEIGHT-1
    BAR 0,0 TO w,h,1
    BAR w,0 TO 2*w,h,2
    BAR 2*w,0 TO 3*w,h,3