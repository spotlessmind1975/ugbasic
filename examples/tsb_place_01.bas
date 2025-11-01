REM TSB PROJECT USING PLACE
REM
REM This example will show the usage for PLACE instruction.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) USANDO PLACE
REM
REM Questo esempio mostrerà l'uso del comando PLACE
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

OPTION DIALECT TSB

10 a$=" ": b$="firstname lastname"
20 c=PLACE(a$,b$)
30 PRINT "the string you are looking for ";
40 IF c THEN : PRINT "is at position"; c: ELSE : PRINT "is not present" : ENDIF

