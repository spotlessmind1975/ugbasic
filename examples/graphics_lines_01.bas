REM @english
REM GRAPHICS PRIMITIVES DRAWING LINES
REM
REM This example will draw two red segments.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI DRAW (1)
REM
REM Questo esempio disegnerà due segmenti rossi.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

   BITMAP ENABLE

   CLS

   INK RED
   DRAW 0,0 TO SCREEN WIDTH - 1, SCREEN HEIGHT - 1

   INK YELLOW
   DRAW TO SCREEN WIDTH / 2, SCREEN HEIGHT / 4
