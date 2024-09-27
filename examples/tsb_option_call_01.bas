REM @english
REM TSB PROJECT USING OPTION CALL PRAGMA
REM
REM This example will show how to use the OPTION CALL pragma.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) USANDO IL PRAGMA OPTION CALL
REM
REM Questo esempio mostrerà come usare il pragma OPTION CALL
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

OPTION CALL AS GOTO

PROC test

	PRINT "ok!"

END PROC

CALL test

