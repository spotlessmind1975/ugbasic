REM ARRAY MANAGEMENT CHECK BOUNDARIES
REM
REM This small example will show how to enable the
REM runtime check boundary.
REM
REM @italian
REM GESTIONE DEGLI ARRAY INIZIALIZZAZIONE
REM
REM Questo piccolo esempio mostra come abilitare
REM il controllo a runtime dei limiti degli indici.
REM
REM @include atari,atarixl,c16,c128,c64,coco,cocob,coco3,coco3b,d32,d32b,d64,d64b,coleco,pc128op,to8,sg1000,sc3000,cpc,vic20,zx,pccga

OPTION ARRAY CHECK

DIM integers(4)

FOR i=0 TO 100
	PRINT integers(i)
NEXT i