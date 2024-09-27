REM TSB PROJECT USING INST
REM
REM This example will show the usage of INST instruction.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) USANTO INST
REM
REM Questo esempio mostrerà l'uso dell'istruzione INST.
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

CLS

10 v$=" vor": n$="nachname" 
20 r$=INST(v$,n$,1) 
30 PRINT "(";r$;")"

