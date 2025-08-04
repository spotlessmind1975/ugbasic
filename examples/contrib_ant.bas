REM @english
REM OTHER CONTRIBUTIONS LANGTON'S ANT
REM
REM Langton's ant is a two-dimensional Turing machine with a very simple set 
REM of rules but complex emergent behavior. It was invented by Chris Langton 
REM in 1986 and runs on a square lattice of black and white cells. The idea 
REM has been generalized in several different ways, such as turmites which 
REM add more colors and more states.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI FORMICA DI LANGTON
REM
REM La formica di Langton è un automa a stati finiti bidimensionale con un
REM insieme di regole molto semplice ma in grado di creare figure molto 
REM complicate. È stato inventato nel 1986 da Chris Langton. 
REM
REM @include atari,cpc,coleco,c128,c64,c64reu,msx,sg1000,sc3000,coco3,

	' Enable BITMAP mode with a black background.
	
	BITMAP ENABLE(320,200)
	CLS BLACK
	
	' Precalculate vectorial directions.
	
	DIM dx(4) AS POSITION = #{ 0, 1, 0, -1 }
	DIM dy(4) AS POSITION = #{ -1, 0, 1, 0 }

	' Define the single ant structure.

	TYPE antType
		x AS POSITION
		y AS POSITION
		d AS SIGNED BYTE
	END TYPE
	
	' Declare a single ant variable.
	
	DIM ant AS antType

	' Put ant at the center of the screen.
	
	ant.x = SCREEN WIDTH / 2
	ant.y = SCREEN HEIGHT / 2

	' Endless loop!
	
	DO

		' Take the color in the current ant's position.
		
		c = POINT(ant.x, ant.y)
		
		' If the current ant's cell color is black...
		
		IF c = BLACK THEN
		
			' Rotate 90° clockwise.
			
			INC ant.d
			IF ant.d = 4 THEN ant.d = 0
			
			' Change the cell's color.
			
			PLOT ant.x, ant.y, WHITE
		
		' ... else, if the color is white...
			
		ELSE
		
			' Rotate 90° counter clockwise

			DEC ant.d
			IF ant.d = -1 THEN ant.d = 3
			
			' Change the cell's color.
			
			PLOT ant.x, ant.y, BLACK
			
		ENDIF
		
		' Move the ant forward.
		
		ADD ant.x, dx(ant.d)
		ADD ant.y, dy(ant.d)
		
		' Pac-man border style :-D
		
		IF ant.x < 0 THEN x = SCREEN WIDTH - 1
		IF ant.x > SCREEN WIDTH - 1 THEN x = 0
		IF ant.y < 0 THEN y = SCREEN HEIGHT - 1
		IF ant.y > SCREEN HEIGHT - 1 THEN y = 0
		
	LOOP

