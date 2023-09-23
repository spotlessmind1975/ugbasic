REM @english
REM BIT DATATYPE USING DATATYPE
REM
REM The ugBASIC language natively supports the "bit" data type. It is a data 
REM type that stores only the value 0 or the value 1. This example shows how 
REM to define a bit variable and how to access it.
REM 
REM @italian
REM TIPO DATO BIT USARE IL TIPO DI DATO
REM
REM Il linguaggio ugBASIC supporta, nativamente, il tipo di dato "bit". 
REM Si tratta di un tipo di dato che memorizza solo il valore 0 oppure il 
REM valore 1. Questo esempio mostra come definire una variabile bit e come 
REM accedervi.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

    CLS
    
    POSITIVE CONST bit0 = 0
    POSITIVE CONST bit1 = 1

    DIM b0 AS BIT = bit0
    DIM b1 AS BIT = bit1

    PRINT "BIT 0 = ";b0
    PRINT "BIT 1 = ";b1
