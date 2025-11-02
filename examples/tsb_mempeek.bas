REM TSB PROJECT USING MEMPEEK
REM
REM This example shows how to use MEMPEEK.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) COME USARE MEMPEEK
REM
REM Questo esempio mostra come usare il comando MEMPEEK
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

a = 42
PRINT "MEMPEEK(...) = ";MEMPEEK(VARPTR(a)); " (should be 42)"


