REM @english
REM SCREEN MANIPULATION BEST RESOLUTION (BITMAP MODE)
REM
REM This example shows the best bitmap mode's characteristics.
REM
REM @italian
REM MANIPOLAZIONE DI SCHERMI CAMBIARE RISOLUZIONE (2)
REM
REM Questo esempio mostra la miglior risoluzione BITMAP disponibile. 
REM
REM @include atari,atarixl,c128,c64

     BITMAP ENABLE
     CLS BLACK: PEN WHITE
     PRINT WIDTH;"x";HEIGHT;" (";COLORS;" colors with ";SHADES;" shades)"
     WAIT KEY
     BITMAP ENABLE(160,200,16)
     CLS BLACK: PEN WHITE
     PRINT WIDTH;"x";HEIGHT;" (";COLORS;" colors with ";SHADES;" shades)"
