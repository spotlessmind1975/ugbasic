REM @english
REM BIT DATATYPE ARRAY OF BITS
REM
REM This example shows how to declare and use an array of bits.
REM 
REM @italian
REM TIPO DATO BIT COMPARAZIONE TRA BIT
REM
REM Questo esempio mostra come dichiarare e usare un array di bit.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx
REM @version beta

    CLS

    DIM a AS BIT(10,10)
    
    a(1,1) = 1
    a(1,2) = 1
    a(1,3) = 1
    a(2,1) = 1
    a(2,2) = 1
    a(2,3) = 1
    a(3,1) = 1
    a(3,2) = 1
    a(3,3) = 1

    FOR y = 0 TO 9
        FOR x = 0 TO 9
            PRINT a(x,y);
        NEXT
        PRINT
    NEXT
