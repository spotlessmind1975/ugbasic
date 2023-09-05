REM @english
REM GRAPHICS PRIMITIVES DRAWING (RANDOM) LINES
REM
REM This example will draw random segments on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI DRAW (2)
REM
REM Questo esempio disegnerà segmenti casuali sullo schermo.
REM
REM @include atari,atarixl,c128,c64

  BITMAP ENABLE(16)
  CLS
  DO
      INK RND(SCREEN COLORS-1)
      DRAW RND(SCREEN WIDTH-1), RND( SCREEN HEIGHT-1) TO _
            RND(SCREEN WIDTH-1), RND( SCREEN HEIGHT-1)
  LOOP