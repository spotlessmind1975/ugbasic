REM @english
REM ARRAY MANAGEMENT BOUNDS
REM
REM This small example will show how to retrieve
REM the bounds of arrays.
REM
REM @italian
REM GESTIONE DEGLI ARRAY LIMITI
REM
REM Questo piccolo esempio mostra come recuperare
REM i limiti degli array.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc,vic20,zx

DIM number(5,4,3)

PRINT "UBOUND(number) should be 5: "; UBOUND(number)
PRINT "UBOUND(number,0) should be 5: "; UBOUND(number,0)
PRINT "UBOUND(number,2) should be 3: "; UBOUND(number,2)
