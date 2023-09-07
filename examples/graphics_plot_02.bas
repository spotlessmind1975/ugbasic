REM @english
REM GRAPHICS PRIMITIVES FILL PLOTTING
REM
REM This example will fill the entire bitmap screen, from top left to bottom right,
REM with the white color. It will enable the first bitmap mode available (in order 
REM to have better resolution) by using the ''BITMAP ENABLE'' command. Then, it
REM will clear the screen with the black color. Finally, it will run a controlled loop
REM (''FOR...NEXT'') that will draw the all pixels.
REM
REM @italian
REM PRIMITIVE DI GRAFICA CON L'USO DI PLOT (2)
REM
REM Questo esempio riempirà l'intero schermo bitmap, dall'alto a sinistra in basso 
REM a destra, con il colore bianco. Abiliterà la prima modalità bitmap disponibile 
REM (in modo da avere una migliore risoluzione) utilizzando il comando 
REM ''BITMAP ENABLE''. Quindi, cancellerà lo schermo con il colore nero. Infine, 
REM eseguirà un ciclo controllato (''FOR...NEXT'') che disegnerà tutti i pixel.
REM
REM @include atari,atarixl,c128,c64,coco,coleco

  BITMAP ENABLE
  CLS BLACK
  COLOR #0, #5
  
  y = (POSITION) 0
  x = (POSITION) 0
  FOR y = 0 TO SCREEN HEIGHT - 1
    FOR x = 0 TO SCREEN WIDTH - 1
      PLOT x,y,WHITE
    NEXT
  NEXT
  