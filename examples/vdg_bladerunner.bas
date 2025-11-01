﻿REM @english
REM VIDEOGAME INSPIRED BLADE RUNNER OPENING
REM
REM This code will draw the opening title of the "Blade Runner" videogame,
REM developed by Westwood Studios and published by Virgin Interactive 
REM for Microsoft Windows, released on November 14, 1997. 
REM
REM This was one of the games that missed out on 8-bit platforms, due 
REM in part to the remarkable software technology introduced, which made 
REM use of voxel-based software renderings instead of hardware accelerator 
REM cards.
REM 
REM With this example we try to outline an isomorphic way of writing 
REM programs and designing graphic resources, so that it is easier to 
REM port them from one platform to another. The aim, as always, is to 
REM guarantee a comparable visual and gaming experience between systems, 
REM without giving up the specificities of each.
REM
REM @italian
REM ISPIRATI AI VIDEOGIOCHI TITOLI DI BLADE RUNNER
REM 
REM Questo codice disegnerà il titolo di apertura del videogioco 
REM "Blade Runner", sviluppato da Westwood Studios e pubblicato 
REM da Virgin Interactive per Microsoft Windows, uscito il 
REM 14 novembre 1997.
REM
REM Questo è stato uno dei videogiochi che hanno mancato le piattaforme 
REM a 8 bit, a causa anche della notevole tecnologia software introdotta, 
REM che faceva uso dei rendering software basati sui voxel invece delle 
REM schede acceleratrici hardware. 
REM 
REM Con questo esempio proviamo a tracciare un modo isomorfo di scrivere 
REM programmi e disegnare risorse grafiche, affinché sia più facile 
REM portarli da una piattaforma all'altra. Lo scopo, come sempre, è 
REM garantire una esperienza visiva e di gioco paragonabile tra i sistemi,
REM senza rinunciare alle specificità di ognuno.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,msx1,sc3000,sg1000,vic20,zx

	' We suggest the use the most coloured
	' resolution (up to 16 colors).
	
	BITMAP ENABLE(16)

	' We clear the graphical screen.
	
	CLS

	' Put the color border to BLACK (if border is preset)
	
	COLOR BORDER BLACK

	' Load from the host the (degrated quality of the) image 
	' of the opening titles of the videogame. 
	'
	' Note that the original image has been converted to 
	' match at best each target, and moved the result into 
	' each folder with the same target name. In particular:
	'
	'	atari / atarixl : 160x96 pixel, 4 colors
	'	c128 			: 160x200 pixel, 16 colors
	'	c128z 			: 320x200 pixel, 2 colors
	'	c64 			: 160x200 pixel, 16 colors
	'	coco 			: 128x192 pixel, 4 colors[edited]
	'	coco3 			: 320x200 pixel, 16 colors
	'	coleco          : 256x160 pixel, 16 colors
	'	cpc 			: 160x200 pixel, 16 colors	
	'	d32 			: 128x192 pixel, 4 colors[edited]
	'	d64 			: 128x192 pixel, 4 colors[edited]
	'	msx1			: 256x160 pixel, 16 colors
	'	sc3000			: 256x160 pixel, 16 colors
	'	sg1000			: 256x160 pixel, 16 colors
	'	vic20 			: 176x184 pixel, 8 colors
	'	zx				: 256x192 pixel, 8 colors
	
	image := LOAD IMAGE("bladerunner.png")

	' Now, we calculate the offset to center the image
	' in the respect of the effective resolution chosen by
	' ugBASIC.
	
	CONST cx = ( SCREEN WIDTH - IMAGE WIDTH(image) ) / 2
	CONST cy = ( SCREEN HEIGHT - IMAGE HEIGHT(image) ) / 2

	' Finally, we draw the image at the center of the screen.
	
	PUT IMAGE image AT cx,cy

