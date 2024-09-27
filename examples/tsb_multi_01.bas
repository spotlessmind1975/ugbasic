REM TSB PROJECT USING MULTI
REM
REM This example will show how to use the MULTI instruction.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) USANDO MULTI
REM
REM Questo esempio mostrerà l'uso del comando MULTI.
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,zx

OPTION DIALECT TSB

HIRES BLACK, WHITE
MULTI RED, GREEN, BLUE

BLOCK 0, 0, 10, 10, 1
BLOCK 2, 2, 12, 12, 2
BLOCK 4, 4, 14, 14, 3

