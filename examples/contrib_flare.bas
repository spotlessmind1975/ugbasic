REM @english
REM OTHER CONTRIBUTIONS FLARE ANIMATION
REM
REM This example is most like creating a video player, inserting 
REM pictures into REU memory. To make this demo, we take a 
REM YouTube video, 8 frames per second for a total of 56 frames. 
REM The frames is resized to 128x128 pixels, composed in a strip 
REM and reproduced, one frame at a time, with the illusion of an
REM animation. The demo can be stored on two floppy disks or in a
REM single 512KB REU image.
REM
REM @url https://www.youtube.com/watch?v=ZyBTz8Pa3NY
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI ANIMAZIONE DI UN BAGLIORE
REM 
REM Questo esempio crea una sorta di lettore video, inserendo 
REM immagini nella memoria REU. Per realizzare questa demo viene 
REM preso un video da YouTube, 8 fotogrammi al secondo per un 
REM totale di 56 fotogrammi. I fotogrammi vengono 
REM ridimensionati a 128x128 pixel, composti in una striscia 
REM e riprodotti, un fotogramma alla volta, con l'illusione 
REM di un'animazione. La demo può essere memorizzata su due 
REM floppy disk o in un'unica immagine REU da 512KB.
REM
REM @url https://www.youtube.com/watch?v=ZyBTz8Pa3NY
REM 
REM @include c64reu

BITMAP ENABLE(16)

strip0 := LOAD IMAGES( "flare-0.png" ) FRAME SIZE (128,128) BANKED
strip1 := LOAD IMAGES( "flare-1.png" ) FRAME SIZE (128,128) BANKED
strip2 := LOAD IMAGES( "flare-2.png" ) FRAME SIZE (128,128) BANKED
strip3 := LOAD IMAGES( "flare-3.png" ) FRAME SIZE (128,128) BANKED
strip4 := LOAD IMAGES( "flare-4.png" ) FRAME SIZE (128,128) BANKED
strip5 := LOAD IMAGES( "flare-5.png" ) FRAME SIZE (128,128) BANKED
strip6 := LOAD IMAGES( "flare-6.png" ) FRAME SIZE (128,128) BANKED
strip7 := LOAD IMAGES( "flare-7.png" ) FRAME SIZE (128,128) BANKED

COLOR BORDER BLACK
CLS BLACK

DIM strip AS BYTE, frame AS BYTE

LOCATE 0,ROWS / 2
INK WHITE

strip = 0

DO

	SELECT CASE strip
		CASE 0
			PUT IMAGE strip0 FRAME frame AT 16, 36
		CASE 1
			PUT IMAGE strip1 FRAME frame AT 16, 36
		CASE 2
			PUT IMAGE strip2 FRAME frame AT 16, 36
		CASE 3
			PUT IMAGE strip3 FRAME frame AT 16, 36
		CASE 4
			PUT IMAGE strip4 FRAME frame AT 16, 36
		CASE 5
			PUT IMAGE strip5 FRAME frame AT 16, 36
		CASE 6
			PUT IMAGE strip6 FRAME frame AT 16, 36
	ENDSELECT
	
	INC frame
	
	IF frame = FRAMES(strip0) THEN
		frame = 0
		INC strip
		IF strip = 7 THEN
			strip = 4
		ENDIF
	ENDIF

LOOP



