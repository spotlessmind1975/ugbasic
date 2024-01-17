REM ASSEMBLY INTEGRATION INLINE (MORE LINES)
REM 
REM This small example explains how to integrate assembly
REM with more line instructions.
REM 
REM @italian
REM INTEGRAZIONE ASSEMBLY INLINE (PIU' LINEE)
REM
REM Questo piccolo esempio spiega come integrare l'assembly
REM con più righe di assembly.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

    DIM x AS BYTE

    x = 42

    ' CPU 6809
    ON CPU6809 BEGIN ASM 
        INC _x
        DEC _x
    END ASM

    BEGIN ASM 
        INC _x
        DEC _x
    END ASM ON CPU6809

    ' CPU DOS
    ON CPU6502 BEGIN ASM 
        INC _x
        DEC _x
    END ASM

    ' CPU DOS
    BEGIN ASM 
        INC _x
        DEC _x
    END ASM ON CPU6502

    ON CPUZ80 BEGIN ASM 
        INC _x
        DEC _x
    END ASM

    BEGIN ASM 
        INC _x
        DEC _x
    END ASM ON CPUZ80 

    IF x = 42 THEN
        PRINT "ok!"
    ELSE
        PRINT "bad!"
    ENDIF
