REM @english
REM COPPER LIST A STATIC RAINBOW
REM 
REM This small example shows how to use the BEGIN COPPER ... END COPPER
REM instructions to create a simple static rainbow.
REM
REM @italian
REM GESTIONE COPPER LIST UN ARCOBALENO STATICO
REM
REM Questo piccolo esempio mostra come utilizzare le istruzioni
REM BEGIN COPPER ... END COPPER per creare un semplice arcobaleno statico.
REM
REM @include atari,atarixl
	
	CONST rainbowStep = 8
	
	BEGIN COPPER "primo"
		WAIT LINE 50
		COLOR BACKGROUND 1
		WAIT LINE 58
		COLOR BACKGROUND 2
		WAIT LINE 66
		COLOR BACKGROUND 3
		WAIT LINE 72
		COLOR BACKGROUND 4
		WAIT LINE 80
		COLOR BACKGROUND BLUE
	END COPPER

	BEGIN COPPER "secondo"
		WAIT LINE 60
		COLOR BACKGROUND RED
		WAIT LINE 80
		COLOR BACKGROUND BLUE
	END COPPER

	SCREEN #13

	CLS
	
	PRINT "ok!"
	
	DO
		WAIT KEY RELEASE
		COPPER USE "primo"
		WAIT KEY RELEASE
		COPPER USE "secondo"
	LOOP
	
	
		