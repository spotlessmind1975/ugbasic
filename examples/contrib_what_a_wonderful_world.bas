REM @english
REM OTHER CONTRIBUTIONS WHAT A WONDERFUL WORLD
REM
REM Some of you young folks been saying to me
REM  Hey Pops, what you mean 'What a wonderful world'?"
REM  How about all them wars all over the place? 
REM  You call them wonderful?
REM  And how about hunger and pollution? 
REM  That ain't so wonderful either.
REM
REM Well how about listening to old Pops for a minute. 
REM Seems to me, it aint the world that's so bad 
REM but what we're doin' to it.
REM
REM - Louis Armstrong (August 4, 1901 -- July 6, 1971), 
REM   nicknamed Satchmo or Pops
REM
REM @italian
REM VARI ALTRI CONTRIBUTI CHE MONDO MERAVIGLIOSO
REM 
REM Alcuni di voi giovani mi hanno detto:
REM  ehi Pops, cosa intendi con 'Che mondo meraviglioso'?
REM  che ne dici di tutte quelle guerre ovunque?
REM  le chiami meravigliose?
REM  e che dire della fame e dell'inquinamento?
REM  neanche questo è così meraviglioso!
REM
REM Beh, che ne dici di ascoltare il vecchio Pops per un minuto.
REM Mi sembra che non sia il mondo a essere così brutto
REM ma cosa gli stiamo facendo.
REM
REM - Louis Armstrong (August 4, 1901 -- July 6, 1971), 
REM   chiamato anche Satchmo o Pops
REM

DEFINE STRING SPACE 512
DEFINE STRING COUNT 64
DEFINE TASK COUNT 2

BITMAP ENABLE(16)

COLOR BORDER WHITE

CLS WHITE

soundtrack := LOAD MUSIC("what_a_wonderful_world.mid")

earth := LOAD IMAGES("earth_128x128_2colors.gif") FRAME SIZE(128,128)

POSITIVE CONST centerX = ( SCREEN WIDTH - 128 ) \ #2
POSITIVE CONST frameMax = FRAMES(earth) - 1

MUSIC soundtrack

PARALLEL PROCEDURE rotatingEarth

	SHARED earth
	
	DIM frame AS BYTE
	DIM t AS WORD
	DIM delay AS WORD
	
	t = TIMER
	delay = ( TICKS PER SECOND / 5 )
	
	DO
	
		WAIT WHILE ( TIMER - t ) < delay
		
		t = TIMER
		
		PUT IMAGE earth FRAME frame AT centerX, 0
		ADD frame, 1, 0 TO frameMax
		
	LOOP

END PROC

PARALLEL PROCEDURE printLyrics

	DIM line AS BYTE
	DIM t AS WORD
	DIM delay AS WORD
	
	t = TIMER
	delay = 2 * TICKS PER SECOND
	
	DO

		WAIT WHILE ( TIMER - t ) < delay

		t = TIMER

		LOCATE 0, SCREEN ROWS - 2
		CLINE
		LOCATE 0, SCREEN ROWS - 3
		CLINE
		
		INK RED
		
		SELECT CASE line
			CASE 0
				CENTER "I see trees of green";
			CASE 1			
				CENTER "Red roses too";
			CASE 2
				CENTER "I see them bloom";
			CASE 3
				CENTER "For me and you";
			CASE 4
				CENTER "And I think to myself";
			CASE 5
				CENTER "What a wonderful world!";
			CASE 7
				CENTER "I see skies of blue";
			CASE 8
				CENTER "And clouds of white";
			CASE 9
				CENTER "The bright blessed day";
			CASE 10
				CENTER "The dark sacred night";
			CASE 11
				CENTER "And I think to myself";
			CASE 12
				CENTER "What a wonderful world";
			CASE 13
				CENTER "The colors of the rainbow";
			CASE 14
				CENTER "So pretty in the sky";
			CASE 15
				CENTER "Are also on the faces";
			CASE 16
				CENTER "Of people going by";
			CASE 17
				CENTER "I see friends shaking hands";
			CASE 18
				CENTER "Saying, How do you do?";
			CASE 19
				CENTER "They're really saying";
			CASE 20
				CENTER "I love you...";
			CASE 21
				CENTER "I hear babies cry";
			CASE 22
				CENTER "I watch them grow";
			CASE 23
				CENTER "They'll learn much more";
			CASE 24
				CENTER "Than I'll ever know";
			CASE 26
				CENTER "And I think to myself";
			CASE 31
				CENTER "What a wonderful world";
			CASE 36
				CENTER "Yes, I think to myself";
			CASE 40
				CENTER "What a wonderful world";
			CASE 44
				CENTER "Ooh, yes...";
		ENDSELECT
		
		INC line
		
	LOOP

END PROC

SPAWN rotatingEarth
SPAWN printLyrics

DO: RUN PARALLEL: LOOP


