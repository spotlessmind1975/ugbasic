REM @english
REM GRAPHICS PRIMITIVES DRAWING (PATTERNED) BOXES
REM
REM This example will draw two boxes with a simple pattern.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI BOX E PATTERN
REM
REM Questo esempio disegnerà due box con dei semplici pattern.
REM
REM @include atari,atarixl,c128,c64,coco

    BITMAP ENABLE

    CLS

    INK YELLOW

    SET LINE $f0f0
    BOX 0, 0 TO SCREEN WIDTH / 4, SCREEN HEIGHT / 4

pippero:

    SET LINE %1100110011001100
    BOX 8, 8 TO SCREEN WIDTH / 4, SCREEN HEIGHT / 4

