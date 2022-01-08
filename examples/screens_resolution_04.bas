REM @english
REM SCREEN MANIPULATION BEST BITMAP
REM
REM This example shows the best bitmap mode's characteristics.
REM
REM @italian
REM MANIPOLAZIONE DI SCHERMI CAMBIARE RISOLUZIONE (2)
REM
REM Questo esempio mostra la miglior risoluzione BITMAP disponibile. 
REM
REM @exclude coleco

     TILEMAP ENABLE
     CLS BLACK: PEN WHITE
     PRINT WIDTH;"x";HEIGHT;" (";COLORS;" colors with ";SHADES;" shades)"
     PRINT COLUMNS;"x";ROWS;" (";TILES;" tiles)"
     WAIT KEY
     TILEMAP ENABLE(20,20,2)
     CLS BLACK: PEN WHITE
     PRINT WIDTH;"x";HEIGHT;" (";COLORS;" colors with ";SHADES;" shades)"
     PRINT COLUMNS;"x";ROWS;" (";TILES;" tiles)"
