REM @english
REM GRAPHICS PRIMITIVES DRAWING USING DRAW INSTRUCTIONS
REM
REM This example will draw "UG" using drawing instructions.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI BOX E PATTERN
REM
REM Questo esempio disegnerà "UG" utilizzando le istruzioni di disegno
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

    BITMAP ENABLE

    CLS

    DRAW "BM10,10;D4R4U4;BR2NR4D4R4UL2"
