REM @english
REM VIDEOGAME ISPIRED ORVILLE
REM
REM This code will draw the opening title of an fictious videogame,
REM about "The Orville", an American science fiction comedy drama.
REM 
REM With this example we try to outline an isomorphic way of writing 
REM programs and designing graphic resources, so that it is easier to 
REM port them from one platform to another. The aim, as always, is to 
REM guarantee a comparable visual and gaming experience between systems, 
REM without giving up the specificities of each.
REM
REM @italian
REM ISPIRATI AI VIDEOGIOCHI TITOLI DI ORVILLE
REM 
REM Questo codice disegnerà il titolo di apertura di un videogioco
REM di fantasia, ispirato a "The Orville", la serie di fantascienza
REM statunitense.
REM
REM Con questo esempio proviamo a tracciare un modo isomorfo di scrivere 
REM programmi e disegnare risorse grafiche, affinché sia più facile 
REM portarli da una piattaforma all'altra. Lo scopo, come sempre, è 
REM garantire una esperienza visiva e di gioco paragonabile tra i sistemi,
REM senza rinunciare alle specificità di ognuno.
REM
REM @include c64

	' We suggest the use the most coloured
	' resolution (up to 16 colors).
	
	BITMAP ENABLE(16)
	
	' This is the number of stars to be displayed.
	' Currenly there is a maximum number of 32 sprites multiplexed.
	
	CONST starCount = 24

	' This data structure will hold, in one place, the information 
	' related to each individual star we'll draw. Specifically, 
	' we'll keep the (x,y) coordinates, the animation frame 
	' (frame), and the reference to the multiplexed sprite 
	' displayed (sprite).
	
	TYPE starType
		x AS POSITION
		y AS POSITION
		sprite AS MSPRITE
		frame AS BYTE
	END TYPE
	
	' This directive allows you to disable the control over image
	' height constraints, where they are present. In fact, the
	' conversion of images from the modern format to the native format
	' of the target must guarantee some specific constraints. However,
	' where it is ensured that the dimensions of the graphic resources
	' are consistent, it is possible to disable this type of control. 
	' This is in order to be able to load graphic resources that do not 
	' need to respect these constraints, such as resources linked 
	' to sprites.
	
	DEFINE IMAGE FREE HEIGHT
	
	' This pragma allow to delay the refresh of the changes made
	' to multiplexed sprites. They will be stored and reflected 
	' on the screen only when the instruction MSPRITE UPDATE 
	' will be executed.
	
	DEFINE MSPRITE ASYNC
	
	' Let's change the border and background color.
	
	COLOR BORDER BLUE	
	CLS BLUE
	
	' Let's wait for a key press. This trick will
	' allow to initialize the TIMER variable to a really
	' random value, that depends on the key press delay.
	
	INK WHITE
	VHCENTER "PRESS ANY KEY"
	WAIT KEY RELEASE
	
	' Let's initialize the random number generator
	' using the time passed from the execution start.
	
	RANDOMIZE TIMER
	
	' Load from the host the (degrated quality of the) image 
	' of the opening titles of the videogame.
	'
	' Note that the original image has been converted to 
	' match at best each target, and moved the result into 
	' each folder with the same target name. In particular:
	'
	'	c64 			: 160x200 pixel, 16 colors
	
	background := LOAD IMAGE("vdg_orville.png")

	' Load from the host the (degrated quality of the) image 
	' of the animated sprites of the rotating stars.
	
	star := LOAD ATLAS("vdg_orville_star.png") FRAME SIZE (24,21)

	' Finally, load from the host the music track, in MIDI
	' format. It will be converted to the native format, as well.
	 
	music := LOAD MUSIC("vdg_orville.mid")

	' Let's create an array that will hold separate 
	' information for each star.
	
	DIM stars(starCount) AS starType
	
	' Now let's initialize each individual star...
	
	FOR i = LBOUND(stars) TO UBOUND(stars)
	
		' The horizontal starting position is from 0 to 319.
		
		stars(i).x = RND(320)
		
		' The vertical starting position starts from 52 
		' and go down of 8 pixel for each star. Note that
		' the vertical screen resolution could be not high
		' enough to keep all the sprites. 
		
		stars(i).y = 52+i*8
		
		' Assign the sprite resource to this sspecific star.
		' We use the IMAGE( ) function to extract the image
		' from the loaded ATLAS (using the FRAME 0 for the 
		' first one). Then, we use the MSPRITE instruction to
		' convert the bitmap into a sprite resource, and using
		' the IGNORE COLOR LIGHT GREEN we are saying that
		' that color will be used as "transparency" for the
		' sprite.
		
		stars(i).sprite = MSPRITE( IMAGE( star FRAME 0 ) IGNORE COLOR LIGHT GREEN )
		
		' Each star starts from a random frame (0..3).
		
		stars(i).frame = RND(4)

		' We can enable the sprite.
		
		SPRITE stars(i).sprite ENABLE
		
	NEXT i
	
	' Put the titles on the screen.
	
	PUT IMAGE background AT 0, 0
	
	' Let's start the music.
	
	MUSIC music
	
	' This is an infinite loop, which will update 
	' the stars' positions at each cycle.
	
	DO
	
		' For each star inside the array...
		
		FOR i = LBOUND(stars) TO UBOUND(stars)
		
			' Increment the horizontal position, up to the
			' end of the screen.
			
			ADD stars(i).x, 1+RND(4)
			IF stars(i).x > 350 THEN stars(i).x = 0
			
			' Based on the current frame, we are going
			' to convert the bitmap from the specific
			' frame of the ATLAS into a sprite. Note that
			' we are going to indicate the previous
			' sprite, in order to "replace" the image.
			
			SELECT CASE stars(i).frame
				CASE 0
					stars(i).sprite = MSPRITE( IMAGE( star FRAME 0 ), stars(i).sprite IGNORE COLOR LIGHT GREEN )
				CASE 1
					stars(i).sprite = MSPRITE( IMAGE( star FRAME 1 ), stars(i).sprite IGNORE COLOR LIGHT GREEN )
				CASE 2
					stars(i).sprite = MSPRITE( IMAGE( star FRAME 2 ), stars(i).sprite IGNORE COLOR LIGHT GREEN )
				CASE 3
					stars(i).sprite = MSPRITE( IMAGE( star FRAME 3 ), stars(i).sprite IGNORE COLOR LIGHT GREEN )
			ENDSELECT
			
			' Increment the frame, up to the
			' end of the ATLAS' frames.
			
			INC stars(i).frame
			IF stars(i).frame = FRAMES( star ) THEN stars(i).frame = 0

			' Move the star to the specific position.
			
			SPRITE stars(i).sprite AT stars(i).x, stars(i).y
			
		NEXT i
		
		' Update every sprite at once.
		MSPRITE UPDATE
		
	LOOP
