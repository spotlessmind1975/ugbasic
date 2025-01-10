REM @english
REM ANIMATION SUPPORT A RUNNING BOY
REM 
REM This small example shows how to use the ANIMATION / ANIMATE
REM primitive, to implement an unmanaged animation.
REM
REM @italian
REM SUPPORTO PER ANIMAZIONI PERCORSI LINEARI
REM
REM Questo piccolo esempio mostra come utilizzare la primitiva 
REM ANIMATION / ANIMATE per implementare un'animazione non gestita.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,cpc,zx,pc128op,to8

	BITMAP ENABLE(16)

	runningBoyAtlas := LOAD ATLAS("boy.png") FRAME SIZE (32,32)

	ANIMATION LOOP running _
		WITH runningBoyAtlas DELAY 200 _
		USING boy _
		WAIT VBL _
		PRESERVE BACKGROUND

	CLS

	ANIMATE boy WITH running AT 0, 0
	