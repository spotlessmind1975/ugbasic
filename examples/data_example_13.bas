REM @english
REM EMBEDDED DATA USING DYNAMIC RESTORE
REM
REM This small example will show how to use the ''RESTORE'' with a variable.
REM 
REM @italian
REM INCLUDENDO DEI DATI USANDO IL RESTORE DINAMICO
REM
REM Questo piccolo esempio mostra come usare l'istruzione ''DATA LOAD''.
REM In questo esempio usiamo la variante ''READ SAFE''.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

90 CLS
100 DATA 42
200 DATA 84
300 test = 200
400 RESTORE test
500 c = 0
600 READ c : PRINT c
700 IF c = 84 THEN
800   PRINT "ok!"
900 ENDIF

