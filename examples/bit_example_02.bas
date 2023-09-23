REM @english
REM BIT DATATYPE BIT MANIPULATION
REM
REM This example shows how to manipulate BIT type variables.
REM 
REM @italian
REM TIPO DATO BIT MANIPOLAZIONE DEI BIT
REM
REM Questo esempio mostra come manipolare le variabili di tipo BIT.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

    CLS
    
    POSITIVE CONST bit0 = 0
    POSITIVE CONST bit1 = 1

    DIM b0 AS BIT = bit0
    DIM b1 AS BIT = bit1


    PRINT "b0 is now : ";b0; " (exp 0)"
    PRINT "b1 is now : ";b1; " (exp 1)"

    SWAP b0, b1

    PRINT "SWAPPED!"

    PRINT "b0 is now : ";b0; " (exp 1)"
    PRINT "b1 is now : ";b1; " (exp 0)"
