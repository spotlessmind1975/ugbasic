REM @english
REM GRAPHICS PRIMITIVES TEXT COORDINATES (USING X/Y GRAPHIC)
REM
REM This example will show how to pass from screen to text coordinates and viceversa.
REM
REM @italian
REM PRIMITIVE DI GRAFICA COORDINATE DI SCHERMO E DI TESTO (1)
REM
REM Questo esempio mostrerà come passare dalle coordinate schermo a quelle testuali, e viceversa.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

    BITMAP ENABLE (160,200,16)
    CLS
    
    x = X GRAPHIC(3)
    y = Y GRAPHIC(4)

    PRINT "3 cols = ";x;" px"
    PRINT "4 rows = ";y;" px"   
