REM @english
REM GRAPHICS PRIMITIVES USING PLOT (1)
REM
REM This example will fill the entire screen with random points. It will enable
REM the first bitmap mode available (in order to have better resolution) by
REM using the ''BITMAP ENABLE'' command. Then, it will clear the screen with
REM the black color. Finally, it will run an endless loop (''DO...LOOP'')
REM that will draw random points on the screen.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI PLOT (1)
REM
REM Questo esempio riempirà l'intero schermo con punti casuali. Abiliterà la 
REM prima modalità bitmap disponibile (in modo da avere una migliore risoluzione) 
REM utilizzando il comando ''BITMAP ENABLE''. Quindi, cancellerà lo schermo con il
REM colore nero. Infine, eseguirà un ciclo infinito (''DO...LOOP'') che disegnerà 
REM una serie di punti casuali sullo schermo.

   BITMAP ENABLE(16)
   CLS BLACK
   DO
      x = RND(SCREEN WIDTH-1)
      y = RND(SCREEN HEIGHT-1)
      c = RND(SCREEN COLORS-1)
      PLOT x, y, c
   LOOP