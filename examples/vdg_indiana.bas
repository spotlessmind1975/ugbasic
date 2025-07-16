REM @english
REM VIDEOGAME ISPIRED INDIANA JONES
REM
REM This code will draw the opening title of an exploring videogame,
REM inspired by Indiana Jones. 
REM 
REM With this example we try to outline an isomorphic way of writing 
REM programs and designing graphic resources, so that it is easier to 
REM port them from one platform to another. The aim, as always, is to 
REM guarantee a comparable visual and gaming experience between systems, 
REM without giving up the specificities of each.
REM
REM @italian
REM ISPIRATI AI VIDEOGIOCHI TITOLI DI INDIANA JONES
REM 
REM Questo codice disegnerà il titolo di apertura di un videogioco
REM di esplorazione, ispirato a Indiana Jones.
REM
REM Con questo esempio proviamo a tracciare un modo isomorfo di scrivere 
REM programmi e disegnare risorse grafiche, affinché sia più facile 
REM portarli da una piattaforma all'altra. Lo scopo, come sempre, è 
REM garantire una esperienza visiva e di gioco paragonabile tra i sistemi,
REM senza rinunciare alle specificità di ognuno.
REM
REM @include atari atarixl c64 c64reu coleco coco

	' We suggest the use the most coloured
	' resolution (up to 16 colors).
	
	BITMAP ENABLE(16)

	' We clear the graphical screen.

	CLS
	
WAIT KEY

	' Put the color border to BLACK (if border is present)
	
	COLOR BORDER BLACK	

	' Load from the host the (degrated quality of the) image 
	' of the opening titles of the videogame.
	'
	' Note that the original image has been converted to 
	' match at best each target, and moved the result into 
	' each folder with the same target name. In particular:
	'
	'	atari / atarixl : 160x96 pixel, 4 colors
	'	c64 			: 160x200 pixel, 16 colors
	'	coco 			: 128x192 pixel, 4 colors[edited]
	'	coco3 			: 320x200 pixel, 16 colors
	'	coleco          : 256x160 pixel, 16 colors
	'	d32 			: 128x192 pixel, 4 colors[edited]
	'	d64 			: 128x192 pixel, 4 colors[edited]
	'	msx1			: 256x160 pixel, 16 colors
	'	sc3000			: 256x160 pixel, 16 colors
	'	sg1000			: 256x160 pixel, 16 colors
	'	zx				: 256x192 pixel, 8 colors

	titles := LOAD IMAGE("indiana_titles.png")
	
	' Load from the host the (degrated quality of the) image 
	' of the animated sprites of the character.
	
	indiana := LOAD ATLAS("indiana_full.png") FRAME SIZE (32,64)

	' Finally, load from the host the music track, in MIDI
	' format. It will be converted to the native format, as well.
	
	music := LOAD MUSIC("indiana.mid")

' This is a parallel procedure, that is a procedure that
' will be played in a multitasking fashion. Infact,
' it will animate the characted indipendently from
' music and other tasks.

PARALLEL PROCEDURE animateIndiana

	' Let graphical resource of indiana character
	' be accessible inside this procedure.
	SHARED indiana
	
	' This is the current frame to show.
	
	DIM frame AS BYTE
	
	' Start from the first frame.
	
	frame = 0
	PUT IMAGE indiana FRAME frame AT 0, SCREEN HEIGHT - IMAGE HEIGHT(indiana)
	
	' Wait a random time to animate.
	
	WAIT 4000*(1+RND(3)) MS
	
	' Repeat the animation forever.
	
	DO
	
		' Draw a frame on the screen. The character will be
		' drawn at the bottom left of the screeen. The height
		' of the screen and of the image are calculated at
		' compile time.
		
		PUT IMAGE indiana FRAME frame AT 0, SCREEN HEIGHT - IMAGE HEIGHT(indiana)
		
		' Wait some time, to avoid a too fast animation.
		
		WAIT 80 MS
		
		' Move to the next frame.
		
		INC frame
		
		' If animation is finished...
		
		IF frame = ( FRAMES(indiana) - 1 ) THEN
		
			' ... let start from the beginning,
			' and we will wait for a random
			' time, in order to make a more
			' natural animation.
			
			frame = 0
			WAIT 4000*(2+RND(3)) MS
			
		ENDIF
		
	LOOP
	
END PROCEDURE

	' Let start the music!
	
	'MUSIC music

	' Put the titles on the screen!
	
	PUT IMAGE titles AT 0, 0
	
	' Start animation!
	
	SPAWN animateIndiana
	
	' The program finishes here, and it does
	' nothing, but it could do anything else,
	' as long as RUN PARALLEL is called.