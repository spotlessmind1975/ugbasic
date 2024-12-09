REM @english
REM SPRITE MANAGEMENT MULTIPLEXING MULTIPLE SPRITES
REM
REM This example shows how to handle various sprites on a system that 
REM supports sprite multiplexing. It also uses some constructs to 
REM automatically calculate the position of the sprites.
REM
REM @italian
REM GESTIONE DEGLI SPRITE SPRITE MULTIPLI MULTIPLEXATI
REM
REM Questo esempio mostra come gestire vari sprites 
REM su un sistema che supporti il multiplexing degli sprite. Fa anche 
REM uso di alcuni costrutti per calcolare automaticamente la posizione 
REM degli sprite.
REM
REM @include c64,c64reu,c128

	OPTION EXPLICIT
	
	DEFINE IMAGE FREE HEIGHT
	DEFINE MSPRITE ASYNC
	
	BITMAP ENABLE
	
	COLOR BORDER BLACK
	
	CONST maxAlienships = 5
	
	DIM index AS BYTE

	DIM spaceImage AS IMAGE

	DIM spaceshipImage AS IMAGE
	DIM spaceshipSprite AS MSPRITE
	DIM spaceshipLeftMove AS PATH
	DIM spaceshipRightMove AS PATH
	DIM spaceshipMove AS PATH
	DIM spaceshipX AS POSITION, spaceshipY AS POSITION

	DIM alienshipImage AS IMAGE
	DIM alienshipSprite(maxAlienships) AS MSPRITE
	DIM alienshipLeftMove(maxAlienships) AS PATH
	DIM alienshipRightMove(maxAlienships) AS PATH
	DIM alienshipMove(maxAlienships) AS PATH
	DIM alienshipLX(maxAlienships) AS POSITION, alienshipRX(maxAlienships) AS POSITION
	DIM alienshipX AS POSITION, alienshipY AS POSITION

	spaceImage := LOAD IMAGE("space.png")
		
	spaceshipImage := LOAD IMAGE("spaceship.png")
	spaceshipSprite = MSPRITE(spaceshipImage)
	spaceshipLeftMove = CREATE PATH( 200, 200 TO 50, 200 )
	spaceshipRightMove = CREATE PATH( 50, 200 TO 200, 200 )
	spaceshipMove = spaceshipRightMove

	alienshipImage := LOAD IMAGE("alienship.png")
	
	index = 0
	DO
		alienshipSprite(index) = MSPRITE(alienshipImage)
		alienshipLX(index) = index*32
		alienshipRX(index) = 200+index*10
		alienshipLeftMove(index) = CREATE PATH( alienshipRX(index), 60+index*16 TO alienshipLX(index), 60+index*32 )
		alienshipRightMove(index) = CREATE PATH( alienshipLX(index), 60+index*32 TO alienshipRX(index), 60+index*16 )
		alienshipMove(index) = alienshipRightMove(index)
		INC index
		EXIT IF index = maxAlienships
	LOOP

	CLS

	PUT IMAGE spaceImage AT 0, 0

	DO
		TRAVEL spaceshipMove TO spaceshipX, spaceshipY 
		SPRITE spaceshipSprite AT spaceshipX, spaceshipY
		IF spaceshipX = 200 THEN
			spaceshipMove = spaceshipLeftMove
		ELSE IF spaceshipX = 50 THEN
			spaceshipMove = spaceshipRightMove
		ENDIF
		
		index = 0
		DO
			TRAVEL alienshipMove(index) TO alienshipX, alienshipY 
			SPRITE alienshipSprite(index) AT alienshipX, alienshipY
			IF alienshipX = alienshipRX(index) THEN
				alienshipMove(index) = alienshipLeftMove(index)
			ELSE IF alienshipX = alienshipLX(index) THEN
				alienshipMove(index) = alienshipRightMove(index)
			ENDIF
			INC index
			EXIT IF index = maxAlienships		
		LOOP

		MSPRITE UPDATE
	LOOP
