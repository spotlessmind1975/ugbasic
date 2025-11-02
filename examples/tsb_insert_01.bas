REM TSB PROJECT USING INSERT FUNCTION
REM
REM This example will show the usage of the INSERT function.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) USANDO LA FUNZIONE INSERT
REM
REM Questo esempio mostrerà l'utilizzo della funzione INSERT.
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

CLS

10 a$="(nickname) ": b$="firstname lastname" 
20 c$=INSERT(a$,b$,9) 
30 PRINT c$ : REM The resulting output is "firstname (nickname) lastname".

