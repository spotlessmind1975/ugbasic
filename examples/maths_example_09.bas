REM @english
REM MATHEMATIC ROUTINES CONVERTING TO INTEGER
REM
REM This example will convert a number to integer.
REM
REM @italian
REM ROUTINE DI MATEMATICA CONVERSIONE A INTERO
REM
REM Questo esempio mostrerà come convertire un numero a intero.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

    CLS
    
    a = 42.25
    b = INT(a)

    PRINT "INT(42.25) = "; b
