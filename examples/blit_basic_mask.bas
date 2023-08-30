REM @english
REM IMAGE BLITTING BASIC MASKING
REM
REM A classic use for blitting is to render transparent sprites onto 
REM a background. In this example a background image, a sprite, and a 
REM 1-bit mask are used.
REM 
REM @italian
REM BLITTING DI IMMAGINI MASCHERATURA SEMPLICE
REM
REM Un uso classico del blitting è il rendering di sprite trasparenti 
REM su uno sfondo. In questo esempio vengono utilizzate un'immagine 
REM di sfondo, uno sprite e una maschera a 1 bit.
REM

PROCEDURE example ON ALL BUT VIC20, VG5000

	BITMAP ENABLE(16)
	
	CLS BLACK
	
	mask := LOAD IMAGE("blit_mask.png") EXACT TRANSPARENCY BLACK OPACITY LIGHT WHITE
	background := LOAD IMAGE("blit_background.png")
	sprite := LOAD IMAGE("blit_sprite.png")
	
	CONST x = ( SCREEN WIDTH - IMAGE WIDTH(background) ) \ #2
	CONST y = ( SCREEN HEIGHT - IMAGE HEIGHT(background) ) \ #2
	
	PUT IMAGE background AT x,y
	
	REM In the first blit, the mask is blitted onto the background using 
	REM the raster operator AND. Because any value ANDed with 0 equals 0, 
	REM and any value ANDed with 1 is unchanged, black areas are created 
	REM where the actual sprites will appear, while leaving the rest of 
	REM the background alone.
	
	BLIT bop1 AS ( ( SOURCE ) AND ( DESTINATION ) )
	BLIT IMAGE mask AT x+10,y+10 WITH bop1
	
	REM In the second blit, the sprite is blitted onto the newly altered 
	REM background using the raster operator of OR. Because any value 
	REM ORed with 0 is unchanged, the background is unaffected and the 
	REM black areas are filled with the actual sprite image.
	
	BLIT bop2 AS ( ( ( INVERSE ( SOURCE 2 ) ) AND ( SOURCE 1 ) ) OR ( DESTINATION ) )
	BLIT IMAGES sprite, mask AT x+10,y+10 WITH bop2
	
END PROC

CALL example ON ALL BUT VIC20, VG5000
	
	
	
