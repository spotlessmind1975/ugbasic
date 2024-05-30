REM @english
REM BIT MANIPULATION COMBINE NIBBLES
REM
REM The ugBASIC language allows you to combine two nibbles into one byte.
REM 
REM @italian
REM MANIPOLAZIONE DI BIT COMBINARE NIBBLE
REM
REM Il linguaggio ugBASIC consente di combinare due nibble in un byte.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,to8,vg5000,vic20,zx

    CLS

    DIM hi AS BYTE, lo AS BYTE
    
    hi = &H0f
    lo = &H0f
    
    PRINT COMBINE NIBBLE( hi, lo )
    

