REM @english
REM BIT DATATYPE BIT COMPARISON
REM
REM This example shows how to compare BITs and other data types.
REM 
REM @italian
REM TIPO DATO BIT COMPARAZIONE TRA BIT
REM
REM Questo esempio mostra come comparare i BIT tra di loro, e con altri tipi di dato.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

    CLS

    POSITIVE CONST bit0 = 0
    POSITIVE CONST bit1 = 1

    DIM b0 AS BIT = bit0
    DIM b1 AS BIT = bit1

    DIM u0 AS BYTE = 0
    DIM u1 AS BYTE = $ff
    DIM w0 AS WORD = 0
    DIM w1 AS WORD = $ffff
    DIM d0 AS WORD = 0
    DIM d1 AS WORD = $ffffffff

    PRINT "(bit 0) = "

    IF b0 = u0 THEN
        PRINT "  (byte 0) "
    ENDIF

    IF b0 = w0 THEN
        PRINT "  (word 0) "
    ENDIF

    IF b0 = d0 THEN
        PRINT "  (dword 0) "
    ENDIF

    PRINT

    PRINT "(bit 1) = "

    IF b1 = u1 THEN
        PRINT " (byte $ff) "
    ENDIF

    IF b1 = w1 THEN
        PRINT " (word $ffff) "
    ENDIF

    IF b1 = d1 THEN
        PRINT " (dword $fffffff) "
    ENDIF

    PRINT
    