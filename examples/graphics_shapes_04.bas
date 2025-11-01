﻿REM @english
REM GRAPHICS PRIMITIVES DRAWING ENCLOSED CIRCLES
REM
REM This example will draw enclosed circles on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON DISEGNO DI FORME (3)
REM
REM Questo esempio disegnerà cerchi concentrici sullo schermo.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

    BITMAP ENABLE (160,200,16)
    CLS
    FOR i=0 TO 10
        r = ( SCREEN WIDTH / 4 - i*2 )
        IF r > 0 THEN
            CIRCLE SCREEN WIDTH / 2,SCREEN HEIGHT / 2, r
        ENDIF
    NEXT
