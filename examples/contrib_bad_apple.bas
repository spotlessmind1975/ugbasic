REM @english
REM OTHER CONTRIBUTIONS BAD APPLE
REM
REM This example shows how to take advantage of a large memory expansion 
REM (about 160 KB). The frame loading mechanism is carried out directly 
REM by ugBASIC, while what you see here is a simple player.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI BAD APPLE
REM
REM Questo esempio mostra come sfruttare una espansione di memoria di 
REM grandi dimensioni (circa 160 KB). Il meccanismo di caricamento dei 
REM fotogrammi è svolto direttamente da ugBASIC, mentre quello che 
REM vedete qui è un semplice player.
REM
REM @include mo5

    BITMAP ENABLE(16)
    CLS
    
	CONST centerX = ( SCREEN WIDTH - 120 ) / 2
	CONST centerY = ( SCREEN HEIGHT - 100 ) / 2
	
    atlas0  := LOAD IMAGES("badapple-atlas16-0.png" ) FRAME SIZE (120,100) BANKED
    atlas1  := LOAD IMAGES("badapple-atlas16-1.png" ) FRAME SIZE (120,100) BANKED
    atlas2  := LOAD IMAGES("badapple-atlas16-2.png" ) FRAME SIZE (120,100) BANKED
    atlas3  := LOAD IMAGES("badapple-atlas16-3.png" ) FRAME SIZE (120,100) BANKED
    atlas4  := LOAD IMAGES("badapple-atlas16-4.png" ) FRAME SIZE (120,100) BANKED
    atlas5  := LOAD IMAGES("badapple-atlas16-5.png" ) FRAME SIZE (120,100) BANKED
    atlas6  := LOAD IMAGES("badapple-atlas16-6.png" ) FRAME SIZE (120,100) BANKED
    atlas7  := LOAD IMAGES("badapple-atlas16-7.png" ) FRAME SIZE (120,100) BANKED
    atlas8  := LOAD IMAGES("badapple-atlas16-8.png" ) FRAME SIZE (120,100) BANKED
    atlas9  := LOAD IMAGES("badapple-atlas16-9.png" ) FRAME SIZE (120,100) BANKED
    atlas10 := LOAD IMAGES("badapple-atlas16-10.png" ) FRAME SIZE (120,100) BANKED
    atlas11 := LOAD IMAGES("badapple-atlas16-11.png" ) FRAME SIZE (120,100) BANKED
    atlas12 := LOAD IMAGES("badapple-atlas16-12.png" ) FRAME SIZE (120,100) BANKED
    atlas13 := LOAD IMAGES("badapple-atlas16-13.png" ) FRAME SIZE (120,100) BANKED
    atlas14 := LOAD IMAGES("badapple-atlas16-14.png" ) FRAME SIZE (120,100) BANKED
    atlas15 := LOAD IMAGES("badapple-atlas16-15.png" ) FRAME SIZE (120,100) BANKED
    atlas16 := LOAD IMAGES("badapple-atlas16-16.png" ) FRAME SIZE (120,100) BANKED
    atlas17 := LOAD IMAGES("badapple-atlas16-17.png" ) FRAME SIZE (120,100) BANKED
    atlas18 := LOAD IMAGES("badapple-atlas16-18.png" ) FRAME SIZE (120,100) BANKED
    atlas19 := LOAD IMAGES("badapple-atlas16-19.png" ) FRAME SIZE (120,100) BANKED

    frame = (BYTE) 0
    seq = (BYTE) 0

    DO
		WAIT VBL
    	SELECT CASE seq
    		CASE 0
		        PUT IMAGE atlas0 FRAME frame AT centerX, centerY
    		CASE 1
		        PUT IMAGE atlas1 FRAME frame AT centerX, centerY
    		CASE 2
		        PUT IMAGE atlas2 FRAME frame AT centerX, centerY
    		CASE 3
		        PUT IMAGE atlas3 FRAME frame AT centerX, centerY
    		CASE 4
		        PUT IMAGE atlas4 FRAME frame AT centerX, centerY
    		CASE 5
		        PUT IMAGE atlas5 FRAME frame AT centerX, centerY
    		CASE 6
		        PUT IMAGE atlas6 FRAME frame AT centerX, centerY
    		CASE 7
		        PUT IMAGE atlas7 FRAME frame AT centerX, centerY
    		CASE 8
		        PUT IMAGE atlas8 FRAME frame AT centerX, centerY
    		CASE 9
		        PUT IMAGE atlas9 FRAME frame AT centerX, centerY
    		CASE 10
		        PUT IMAGE atlas10 FRAME frame AT centerX, centerY
    		CASE 11
		        PUT IMAGE atlas11 FRAME frame AT centerX, centerY
    		CASE 12
		        PUT IMAGE atlas12 FRAME frame AT centerX, centerY
    		CASE 13
		        PUT IMAGE atlas13 FRAME frame AT centerX, centerY
    		CASE 14
		        PUT IMAGE atlas14 FRAME frame AT centerX, centerY
    		CASE 15
		        PUT IMAGE atlas15 FRAME frame AT centerX, centerY
    		CASE 16
		        PUT IMAGE atlas16 FRAME frame AT centerX, centerY
    		CASE 17
		        PUT IMAGE atlas17 FRAME frame AT centerX, centerY
    		CASE 18
		        PUT IMAGE atlas18 FRAME frame AT centerX, centerY
    		CASE 19
		        PUT IMAGE atlas19 FRAME frame AT centerX, centerY
    	ENDSELECT
        INC frame
        IF frame = 4 THEN
        	frame = 0
        	INC seq
        	IF seq = 20 THEN
        		seq = 0
        	ENDIF
        ENDIF
    LOOP


