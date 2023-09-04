REM @english
REM GRAPHICS PRIMITIVES FILL (PATTERN) PLOT
REM
REM This example will fill the entire bitmap screen, from top left to bottom right,
REM with a two color pattern. It will enable the first bitmap mode available with at least 4 colors
REM by using the ''BITMAP ENABLE'' command. Then, it will clear the screen with the black color.
REM Finally, it will run a controlled loop
REM (''FOR...NEXT'') that will draw the all pixels.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI PLOT (4)
REM
REM Questo esempio riempirà l'intero schermo bitmap, dall'alto a sinistra in basso 
REM a destra, con un pattern a due colori. Abiliterà quindi la prima modalità bitmap disponibile 
REM (in modo da avere una migliore risoluzione) utilizzando il comando 
REM ''BITMAP ENABLE''. Quindi, cancellerà lo schermo con il colore nero. Infine, 
REM eseguirà un ciclo controllato (''FOR...NEXT'') che disegnerà tutti i pixel.
REM
REM @include atari,atarixl

  BITMAP ENABLE (4)
  CLS BLACK
  y = (POSITION) 150
  x = (POSITION) 0
  k = 0
  FOR y = 0 TO SCREEN HEIGHT - 1
    FOR x = 0 TO SCREEN WIDTH - 1
      k = k + 1
      IF k MOD 2 == 0 THEN
        PLOT x,y,RED
      ELSE
        PLOT x,y,YELLOW
      ENDIF
    NEXT
  NEXT
  HALT