REM @english
REM GRAPHICS PRIMITIVES SCREEN AND TEXT COORDINATES (1)
REM
REM This example will show how to pass from screen to text coordinates and viceversa.
REM
REM @italian
REM PRIMITIVE DI GRAFICA COORDINATE DI SCHERMO E DI TESTO (1)
REM
REM Questo esempio mostrerà come passare dalle coordinate schermo a quelle testuali, e viceversa.

    BITMAP ENABLE (160,200,16)

    x = X GRAPHIC(3)
    y = Y GRAPHIC(4)

    PRINT "3 columns = ";x;" pixels"
    PRINT "4 rows    = ";y;" pixels"   