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
	
	CONST rainbowStep = ( 96 / 16 )
	
	SCREEN #13

	BEGIN COPPER
		COLOR BACKGROUND $2f
		WAIT LINE 1 * rainbowStep
		COLOR BACKGROUND $2e
		WAIT LINE 2 * rainbowStep 
		COLOR BACKGROUND $2d
		WAIT LINE 3 * rainbowStep 
		COLOR BACKGROUND $2c
		WAIT LINE 4 * rainbowStep 
		COLOR BACKGROUND $2b
		WAIT LINE 5 * rainbowStep 
		COLOR BACKGROUND $2a
		WAIT LINE 6 * rainbowStep 
		COLOR BACKGROUND $29
		WAIT LINE 7 * rainbowStep 
		COLOR BACKGROUND $28
		WAIT LINE 8 * rainbowStep 
		COLOR BACKGROUND $27
		WAIT LINE 9 * rainbowStep 
		COLOR BACKGROUND $26
		WAIT LINE 10 * rainbowStep 
		COLOR BACKGROUND $25
		WAIT LINE 11 * rainbowStep 
		COLOR BACKGROUND $24
		WAIT LINE 12 * rainbowStep 
		COLOR BACKGROUND $23
		WAIT LINE 13 * rainbowStep 
		COLOR BACKGROUND $22
		WAIT LINE 14 * rainbowStep 
		COLOR BACKGROUND $21
		WAIT LINE 15 * rainbowStep 
		COLOR BACKGROUND $20
	END COPPER
	
	CLS
	
	
		