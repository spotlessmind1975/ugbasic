REM ASSEMBLY INTEGRATION INLINE (1 LINE)
REM 
REM This small example explains how to integrate assembly
REM just with inline instructions.
REM 
REM @italian
REM INTEGRAZIONE ASSEMBLY INLINE (1 LINEA)
REM
REM Questo piccolo esempio spiega come integrare l'assembly
REM in solo una linea di codice
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

    DIM x AS BYTE

    x = 0

    ON CPU6809 ASM INC _x

    ON CPU6502 ASM INC _x

    ON CPUZ80 ASM INC _x

    IF x = 2 THEN
        PRINT "ok!"
    ELSE
        PRINT "bad!"
    ENDIF
