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
REM @include atari,atarixl,c16,c128,c128z,c64,coco,cocob,coco3,coco3b,coleco,cpc,d32,d32b,d64,d64b,mo5,msx1,pc128op,plus4,sc3000,sg1000,to8,vg5000,vic20,zx,pccga

	CLS
	
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

    ' CPU 6502
    ON CPU6502 BEGIN ASM 
        INC _x
        DEC _x
    END ASM

    BEGIN ASM 
        INC _x
        DEC _x
    END ASM ON CPU6502

    ON CPU6510 BEGIN ASM 
        INC _x
        DEC _x
    END ASM

    BEGIN ASM 
        INC _x
        DEC _x
    END ASM ON CPU6510

    ON CPU7501 BEGIN ASM 
        INC _x
        DEC _x
    END ASM

    BEGIN ASM 
        INC _x
        DEC _x
    END ASM ON CPU7501

    ON CPU8501 BEGIN ASM 
        INC _x
        DEC _x
    END ASM

    BEGIN ASM 
        INC _x
        DEC _x
    END ASM ON CPU8501

    ON CPU8502 BEGIN ASM 
        INC _x
        DEC _x
    END ASM

    BEGIN ASM 
        INC _x
        DEC _x
    END ASM ON CPU8502

  '  CPU Z80
    ON CPUZ80 BEGIN ASM 
        LD A, (_x)
        INC A
        DEC A
        LD (_x), A
    END ASM

    BEGIN ASM 
        LD A, (_x)
        INC A
        DEC A
        LD (_x), A
    END ASM ON CPUZ80 

  '  CPU 8086
    ON CPU8086 BEGIN ASM 
        MOV AL, [_x]
        INC AL
        DEC AL
        MOV [_x], AL
    END ASM

    BEGIN ASM 
        MOV AL, [_x]
        INC AL
        DEC AL
        MOV [_x], AL
    END ASM ON CPU8086 
    
    IF x = 42 THEN
        PRINT "ok!"
    ELSE
        PRINT "bad!"
    ENDIF

