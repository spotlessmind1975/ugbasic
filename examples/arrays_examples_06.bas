﻿REM @english
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
REM @include atari,atarixl,c16,c128,c64,coco,cocob,coco3,coco3b,d32,d32b,d64,d64b,coleco,pc128op,to8,sg1000,sc3000,cpc,vic20,zx,pccga

DIM number(5,4,3)

PRINT "UBOUND(number) should be 4: "; UBOUND(number)
PRINT "UBOUND(number,0) should be 4: "; UBOUND(number,0)
PRINT "UBOUND(number,2) should be 2: "; UBOUND(number,2)
