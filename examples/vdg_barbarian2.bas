REM @english
REM VIDEOGAME ISPIRED BARBARIAN
REM
REM This example offers the possibility of illustrating how you can manage 
REM elements, even large ones, without the need for hardware sprites. 
REM In particular, this example uses double buffering and, 
REM to have the maximum availability of colors, the artifacts induced by the 
REM NTSC television standard. This version does not use the FLIP to 
REM invert player direction.
REM
REM @italian
REM ISPIRATI AI VIDEOGIOCHI BARBARIAN
REM 
REM Questo esempio offre la possibilità di illustrare come si possano 
REM gestire elementi, anche di grandi dimensioni, senza la necessità di 
REM avere sprite hardware. In particolare, questo esempio sfrutta 
REM il double buffering e, per avere la massima disponibilità 
REM di colori, gli artefatti indotti dallo standard televisivo NTSC.
REM Questa versione non usa il comando FLIP per invertire la direzione
REM del giocatore.
REM
REM @include coco

PROCEDURE demo ON COCO

	SCREEN #14 : COLOR #0,#5
	
	CLS			
	
	DOUBLE BUFFER ON	
	
	scenery := LOAD IMAGE("vdg_barbarian_scenery.png")
	character := LOAD ATLAS("vdg_barbarian_character_full.png") FRAME SIZE(32,64) TRANSPARENCY
	background := NEW IMAGE(32,64)
	
	PUT IMAGE scenery AT 0, 0
	
	SCREEN SWAP
	
	ox# = 49: oy# = 50
	x# = 50: y# = 50
	b# = 0: cd# = 0
	d# = 0
	f# = 0: df# = 0
	
	DO
		IF x <> ox OR y <> oy THEN
			IF x > ox THEN cd = 0
			IF x < ox THEN cd = 1
			IF d <> cd THEN
				IF d = 0 THEN
					df = 4
					d = 1
				ELSE
					df = 0
					d = 0
				ENDIF
			ENDIF
			IF b THEN
				PUT IMAGE background AT ox, oy
			ENDIF
			b = 1
			GET IMAGE background FROM x,y
			PUT IMAGE character FRAME df+f AT x, y WITH TRANSPARENCY
			ADD f, 1, 0 TO (FRAMES(character)/2)-1
			ox = x: oy = y
			SCREEN SWAP
		ENDIF
		JMOVE ,x,y,10,200,10,180,8,8
	LOOP
	
END PROCEDURE

	demo[] ON COCO
