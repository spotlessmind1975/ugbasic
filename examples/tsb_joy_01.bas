REM TSB PROJECT USING JOYSTICK
REM
REM This example will show the return values of the JOY function,
REM if the Simons' BASIC convention is enabled.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) USANDO IL JOYSTICK
REM
REM Questo esempio mostrerà quali sono i valori restituiti 
REM dalla funzione JOY, laddove sia attiva la convenzione del
REM Simon's BASIC.
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

CLS

DEFINE JOYSTICK VALUES TSB

DO
	HOME: PRINT JOY(0);
LOOP
