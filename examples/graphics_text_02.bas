REM @english
REM GRAPHICS PRIMITIVES SCREEN AND TEXT COORDINATES (2)
REM
REM This example will show how to pass from screen to text coordinates and viceversa.
REM
REM @italian
REM PRIMITIVE DI GRAFICA COORDINATE DI SCHERMO E DI TESTO (2)
REM
REM Questo esempio mostrerà come passare dalle coordinate schermo a quelle testuali, e viceversa.

    BITMAP ENABLE (160,200,16)
    CLS
    
    PRINT X GRAPHIC(1), Y GRAPHIC(2)
    BOX X GRAPHIC(10), Y GRAPHIC(10) TO X GRAPHIC(13), Y GRAPHIC(11)
    LOCATE 10,10: PRINT "BOX"
