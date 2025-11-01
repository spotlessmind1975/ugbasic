REM @english
REM SCREEN MANIPULATION CHECK RESOLUTION
REM
REM This example shows how to use the various ''BITMAP'' and ''TILEMAP''
REM resolutions. After each command, the screen will be configured at the
REM best allowed. If a given parameter is omitted, this means that we have
REM no particular interest in that component. The ''BITMAP ENABLE'' and
REM ''TILEMAP ENABLE'' commands wait for up to three parameters: the width,
REM the height and the number of colors. Width and height are measured in pixels
REM (if ''BITMAP'' mode) or in tiles (if ''TILEMAP'' mode). Colors are always
REM individual -- i.e. the maximum number of different colors allowed.
REM
REM @italian
REM MANIPOLAZIONE DI SCHERMI CAMBIARE RISOLUZIONE (2)
REM
REM Questo esempio mostra come utilizzare le varie risoluzioni ''BITMAP'' e ''TILEMAP''. 
REM Dopo ogni comando, lo schermo sarà configurato al meglio consentito. 
REM Se un dato parametro viene omesso, significa che non abbiamo un particolare 
REM interesse per quel componente. I comandi ''BITMAP ENABLE'' e ''TILEMAP ENABLE'' 
REM attendono fino a tre parametri: la larghezza, l'altezza e il numero di colori. 
REM Larghezza e altezza sono misurate in pixel (se modalità ''BITMAP'') o in tile 
REM (se modalità ''TILEMAP''). I colori sono sempre individuali, ovvero il numero 
REM massimo di colori diversi consentiti.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,cpc

     BITMAP ENABLE (320,200)
     CLS
     w = SCREEN WIDTH
     h = SCREEN HEIGHT
     c = COLOR COUNT
     PRINT "bitmap of ";w;"x";h;" pixels (";c;" colors)"
     CENTER "> press any key <"
     PRINT ""

     WAIT KEY

     TILEMAP ENABLE
     CLS
     w = SCREEN COLUMNS
     h = SCREEN ROWS
     c = COLOR COUNT
     PRINT "tilemap of ";w;"x";h;" tiles (";c;" colors)"
