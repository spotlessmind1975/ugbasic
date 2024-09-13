REM TSB PROJECT OPTION CENTER AND NEW LINES
REM
REM This example will check the CENTER pragma, used to change
REM the default behaviour of new line after a CENTER command.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) PRAGMA CENTER NEW LINE
REM
REM Questo esempio verificherà il pragma CENTER, usato per cambiare
REM il comportamento di una "nuova linea" dopo un comando CENTER.
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

CLS

CENTER "With new line"

DEFINE CENTER WITHOUT NEWLINE

CENTER "Without new line"
CENTER "xxxx"

