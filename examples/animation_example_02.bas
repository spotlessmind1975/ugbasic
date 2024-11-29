REM @english
REM ANIMATION SUPPORT A MOVING BOY
REM
REM This small example shows how to use the MOVEMENT / MOVE
REM primitives, to implement an unmanaged movement.
REM
REM @italian
REM SUPPORTO PER ANIMAZIONI UN RAGAZZO CHE SI MUOVE
REM
REM Questo piccolo esempio mostra come utilizzare le primitive 
REM MOVEMENT / MOVE per implementare un movimento non gestito.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,cpc,zx,pc128op,to8

	BITMAP ENABLE(16)
	
	runningBoyAtlas := LOAD ATLAS("boy.png") FRAME SIZE (32,32)

	ANIMATION LOOP running _
		WITH runningBoyAtlas DELAY 200 _
		USING boy _
		WAIT VBL _
		PRESERVE BACKGROUND
	MOVEMENT right RIGHT _
		WITH runningBoyAtlas DELAY 50 _
		USING boy
		
	CLS

	ANIMATE boy WITH running AT 0, 0

	steps = 10
	
	DO
		IF NOT MOVING( boy ) THEN
			MOVE boy WITH right
			DEC steps
			EXIT IF steps = 0
		ENDIF
		RUN PARALLEL
	LOOP	
	