REM @english
REM MATHEMATIC ROUTINES SOME SIGNED OPERATIONS
REM
REM This example will show some calculation with signed numbers.
REM
REM @italian
REM ROUTINE DI MATEMATICA OPERAZIONI CON SEGNO
REM
REM Questo esempio mostrerà alcuni calcoli con numeri con il segno.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc

    CLS
    
    a = 42
    b = 21
    c = -(a*b)

    PRINT "-(42*21) = "; c
