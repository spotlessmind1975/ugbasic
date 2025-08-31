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
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,pc128op,to8,sg1000,sc3000,cpc,vic20,zx,pccga

OPTION ARRAY CHECK

DIM integers(4)

FOR i=0 TO 100
	PRINT integers(i)
NEXT i