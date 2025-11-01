REM @english
REM SPRITE MANAGEMENT MULTIPLEXING A BIG SPRITE
REM
REM This example shows how to handle a large sprite on a system that 
REM supports sprite multiplexing. It also uses some constructs to 
REM automatically calculate the position of the sprites.
REM
REM @italian
REM GESTIONE DEGLI SPRITE MULTIPLEXING CON UN GRANDE SPRITE
REM
REM Questo esempio mostra come gestire uno sprite di grandi dimensioni 
REM su un sistema che supporti il multiplexing degli sprite. Fa anche 
REM uso di alcuni costrutti per calcolare automaticamente la posizione 
REM degli sprite.
REM
REM @include c64,c64reu,c128

	OPTION EXPLICIT
	
	DEFINE IMAGE FREE HEIGHT
	DEFINE MSPRITE ASYNC
	
	BITMAP ENABLE
	
	COLOR BORDER GREEN
	
	DIM forestImage AS IMAGE

	DIM dragonBirdImage AS IMAGE
	DIM dragonBirdSprite AS MSPRITE
	DIM dragonBirdMove AS PATH
	DIM dragonBirdLeftMove AS PATH
	DIM dragonBirdRightMove AS PATH
	DIM dragonBirdX AS POSITION, dragonBirdY AS POSITION

	forestImage := LOAD IMAGE("forest.png")		

	dragonBirdLeftMove = CREATE PATH( 300, 52 TO 0, 52 )
	dragonBirdMove = dragonBirdRightMove
	dragonBirdImage := LOAD IMAGE("dragonbird.png")		
	dragonBirdSprite = MSPRITE(dragonBirdImage IGNORE COLOR LIGHT RED)
	
	CLS

	PUT IMAGE forestImage AT 0, 0

	DO
		TRAVEL dragonBirdMove TO dragonBirdX, dragonBirdY 
		SPRITE dragonBirdSprite AT dragonBirdX, dragonBirdY
		IF dragonBirdX = 0 THEN
			dragonBirdMove = dragonBirdLeftMove
		ENDIF
		MSPRITE UPDATE
	LOOP
