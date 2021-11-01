REM @english
REM GRAPHICS PRIMITIVES USING PLOT (5)
REM
REM This example has been added to check the fix #188.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI PLOT (5)
REM
REM Questo esempio è stato aggiunto per controllare il fix #188.

   BITMAP ENABLE
   COLOR BORDER BLACK
   CLS BLACK
   DO
      x=RND(SCREEN WIDTH)
      y=RND(SCREEN HEIGHT)
      c=RND(SCREEN COLORS)
      PRINT x,y,c
      PLOT x,y,c
   LOOP