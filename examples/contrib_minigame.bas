REM @english
REM OTHER CONTRIBUTIONS MINIGAME
REM
REM This is a short game by Endi Baráth, originally published on the 
REM BASIC Programming Language group. It was converted to ugBASIC 
REM by Marco Spedaletti, to work on most 8-bit computers. It needs
REM at least the 1.6.2-beta to compile. A reference to the original
REM source has been added as comment.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI MINIGIOCO
REM
REM Questo è un breve gioco di Endi Baráth, originariamente pubblicato 
REM sul gruppo BASIC Programming Language. E' stato convertito in 
REM ugBASIC da Marco Spedaletti, perché funzionasse sulla maggior 
REM parte dei computer a 8 bit. E' neecssario disporre almeno della
REM version 1.6.2-beta per compilarsi. Un riferimento al sorgente
REM originale è stato aggiunto come commento.
REM 
REM @url https://www.facebook.com/groups/2057165187928233/posts/3681144192196983/
REM
REM @include atari,atarixl,c128,c64,c64reu,coco,coco3,d32,d64,msx1,pc128op,coleco,mo5,to8,sg1000,sc3000,cpc,zx

' It is necessary to apply some techniques to reduce the memory actually 
' used, so that the game can run even on rather limited platforms, 
' such as ColecoVision.

' First, let's proceed to reduce the space occupied by dynamic strings. 
' In ugBASIC this space, despite being dynamic, is statically allocated 
' and occupies a certain memory space. With those pragmas we tell ugBASIC 
' that we will never use more than 8 strings by a total of 32 bytes. 
' Static strings, such as those in quotes, don't count.

DEFINE STRING SPACE 32
DEFINE STRING COUNT 8

' This procedure reads the fire button if a joystick is available.

PROCEDURE control ON JOYSTICK AVAILABLE
	IF JFIRE(0) THEN
		RETURN TRUE		
	ELSE
		RETURN FALSE
	ENDIF
END PROC

' This procedure reads the space bar if a joystick is not available.

PROCEDURE control ON JOYSTICK NOT AVAILABLE
	IF KEY STATE(KEY SPACE) THEN
		RETURN TRUE		
	ELSE
		RETURN FALSE
	ENDIF
END PROC

' ------------------------------------------------------------------
' 100 GRAPHICS HIRES 4:SET BORDER 0:SET KEY CLICK OFF:SET STATUS OFF
' ------------------------------------------------------------------

' We enable the "bitmap" graphics mode. This is the mode in which 
' each individual pixel can be addressed individually, via primitive 
' commands, such as those related to drawing a single pixel.

BITMAP ENABLE

' We set the border color to black, at least for those targets for 
' which this instruction makes sense. Since ugBASIC is an isomorphic 
' language, it does not provide an abstraction of the concept of 
' "border". Therefore, if the border exists, it will be colored, 
' otherwise this statement corresponds to a "no operation".

COLOR BORDER BLACK

' Let's define the (pixel) coordinates of the play field:
'
'    (x1,y1) +---------+
'            |         |
'            |         |
'            +---------+ (x2,y2)

POSITIVE CONST x1 = SCREEN WIDTH / 10 
POSITIVE CONST x2 = x1 + (8 * ( SCREEN WIDTH / 10 ))
POSITIVE CONST y1 = SCREEN HEIGHT / 10 
POSITIVE CONST y2 = y1 + (7 * ( SCREEN HEIGHT / 10 ))

' Let's define the (characters) coordinates of the play field:
'
'  (,r1) --> INSTRUCTIONS
'            +---------+
'            |         |
'            |         |
'            +---------+
'    (,r2) --> COMMAND

POSITIVE CONST r1 = 0
POSITIVE CONST r2 = ROWS-2

' Instructions string. The lenght of this string depends on
' the width of the text screen.

CONST instructions = IF(COLUMNS < 40, "press to turn", "GAME: press to turn direction")
CONST final = IF(COLUMNS < 40, "SCORE: ", "YOUR SCORE: ")

' Repeat forever

DO

	' With this instruction we clear the screen, using (if possible) the color 
	' black. Remembering that ugBASIC is an isomorphic language, it is possible 
	' that the color indication is ignored, or a similar one is chosen.
	
	CLS BLACK
	
	' Let's memorize the status of fire and the previous state itself.
	' This allow to track the fact that the fire has been released.
	
	joy = FALSE: joyp = FALSE
	
	' ----------------------------------------------------------
	' 110 SET INK 2:PLOT 500,200;800,200;800,500;500,500;500,200
	' ----------------------------------------------------------
	
	' Let's draw the yellow box as playfield.
	
	BOX x1,y1 TO x2,y2,YELLOW
	
	' ------------------------------------------------------------
	' 120 PRINT #101,AT 2,2:"GAME: press a key to turn direction."
	' ------------------------------------------------------------
	
	' Let's print the intructions at the center of the line.
	
	LOCATE ,r1
	CENTER instructions;
	
	' -------------------------------------------------
	' 130 SET INK 3:LET I=0:LET X=550:LET Y=220:LET S=0
	' -------------------------------------------------
	
	i = 0
	x = x1+x1
	y = y1+y1
	s = 0
	
	'            +---------+
	'            | * (x,y) |
	'            |         |
	'            +---------+
	
	' Forever loop until finish.
	
	DO
	
	' ---------------------------
	' 140 LET I$=INKEY$:LET S=S+1
	' ---------------------------
	
		' Slow down the program a bit, to make it playable.
		
		WAIT 25 MS
	
		' Let's record if the button has been pressed AND released.
	
		IF joy THEN
			IF control[] = 0 THEN
				joyp = TRUE
				joy = FALSE
			ENDIF
		ELSE
			joy = control[]
		ENDIF
		
		' Increment the score!
		
		INC s
	
		' -------------
		' 150 PLOT X,Y,
		' 160 LOOK A
		' -------------
		
		' Take the color of destination pixel.
		
		a = POINT(x,y)
	
		' Draw a pixel on it.
		
		PLOT x,y,WHITE
	
		' ---------------------------------------
		' 170 PLOT X,Y
		' 180 IF I$ ≠ "" THEN LET I= (I+1) BAND 3
		' ---------------------------------------
		
		' Each time the fire / space bar is pressed, the
		' direction will be changed, in a clockwise manner.
		' The (i+1) increment the direction, while the AND
		' 3 will limit the value from 0 to 3.
		'
		'             3
		'             ^
		'         2 <-+-> 0
		'             v
		'             1
		
		IF joyp THEN i = (i+1) AND 3
	
		' Reset the button.
		
		joyp = FALSE
	
		' -----------------------------------
		' 190 IF I=0 THEN LET X=X+4:LET Y=Y+0
		' -----------------------------------
		
		' Move the point to the right.
		
		IF i=0 THEN INC x
	
		' -----------------------------------
		' 200 IF I=1 THEN LET X=X+0:LET Y=Y+4
		' -----------------------------------
	
		' Move the point down.
		
		IF i=1 THEN INC y
	
		' -----------------------------------
		' 210 IF I=2 THEN LET X=X-4:LET Y=Y+0
		' -----------------------------------
	
		' Move the point to the left.
	
		IF i=2 THEN DEC x
	
		' -----------------------------------
		' 220 IF I=3 THEN LET X=X+0:LET Y=Y-4
		' -----------------------------------
	
		' Move the point to the right.
		
		IF i=3 THEN DEC y
	
		' ------------------------
		' 230 IF A=0 THEN GOTO 140
		' ------------------------
	
		' If the underlying pixel is black, we can move
		' to the next position along the selected direction.
		' Oherwise, we can exit.
		
		EXIT IF a<>BLACK
	
	LOOP
	
	' ---------------------------------------
	' 240 PRINT #101,AT 19,12:"YOUR SCORE:";S
	' ---------------------------------------
	
	' Print the score and ends.
	
	BELL
	
	LOCATE , r2
	CENTER final+STR$(s);
	
	' Wait a key / fire to restart
	
	WAIT KEY OR FIRE RELEASE
	
LOOP
