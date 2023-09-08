REM EXTERNAL INTEGRATION ASM INLINE
REM 
REM This small example explains how to include ASM inline.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO ASSEMBLY INLINEA
REM
REM Questo piccolo esempio spiega come include codice ASM in linea.
REM
REM @include atari,atarixl,c128,c64,coco,coleco,cpc

    CLS

    ON CPU6502 ASM LDA #$42
    ON CPU6809 ASM LDA #$42
    ON CPUZ80 ASM LD A, $42
