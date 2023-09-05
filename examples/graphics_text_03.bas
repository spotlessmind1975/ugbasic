REM @english
REM GRAPHICS PRIMITIVES TEXT COORDINATES (USING X/Y TEXT)
REM
REM This example will show how to pass from screen to text coordinates and viceversa.
REM
REM @italian
REM PRIMITIVE DI GRAFICA COORDINATE DI SCHERMO E DI TESTO (2)
REM
REM Questo esempio mostrerà come passare dalle coordinate schermo a quelle testuali, e viceversa.
REM
REM @include atari,atarixl,c128,c64

    BITMAP ENABLE (160,200,16)
    CLS

    PRINT X TEXT(8),Y TEXT(16)
    PRINT X TEXT(10),Y TEXT(20)
    BAR 80, 80 TO 100, 100
    LOCATE X TEXT(80),Y TEXT(80): PRINT "TESTING!"
