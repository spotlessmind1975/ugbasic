REM @english
REM SCREEN MANIPULATION BEST RESOLUTION (TILEMAP MODE)
REM
REM This example shows the best bitmap mode's characteristics.
REM
REM @italian
REM MANIPOLAZIONE DI SCHERMI CAMBIARE RISOLUZIONE (2)
REM
REM Questo esempio mostra la miglior risoluzione BITMAP disponibile. 
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,cpc

     TILEMAP ENABLE
     CLS BLACK: PEN WHITE
     PRINT WIDTH;"x";HEIGHT;" (";COLORS;" colors with ";SHADES;" shades)"
     PRINT COLUMNS;"x";ROWS;" (";TILES COUNT;" tiles)"
     WAIT KEY
     TILEMAP ENABLE(20,20,2)
     CLS BLACK: PEN WHITE
     PRINT WIDTH;"x";HEIGHT;" (";COLORS;" colors with ";SHADES;" shades)"
     PRINT COLUMNS;"x";ROWS;" (";TILES COUNT;" tiles)"
