REM @english
REM OTHER CONTRIBUTIONS TEST CARD
REM
REM A test card, also known as a test pattern or start-up/closedown test, is a television test
REM signal, typically broadcast at times when the transmitter is active but no program is being 
REM broadcast. They are electronically generated test patterns, used for calibrating or 
REM troubleshooting the video output.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI SCHEDA DI TEST
REM
REM Una "scheda di test" (test card), nota anche come modello di test o test di avvio/spegnimento, 
REM è un segnale di test televisivo, generalmente trasmesso negli orari in cui il trasmettitore 
REM è attivo ma non viene trasmesso alcun programma. Sono modelli di test generati 
REM elettronicamente, utilizzati per calibrare o risolvere i problemi dell'uscita video.
REM
REM @include c128,c64,coco3,cpc,pc128op,msx1

OPTION EXPLICIT

BITMAP ENABLE (16)
COLOR BORDER BLACK
CLS BLACK

POSITIVE CONST cardColor = WHITE
POSITIVE CONST cardWidth = SCREEN WIDTH / 10
POSITIVE CONST cardHeight = SCREEN HEIGHT / 10
POSITIVE CONST verticalLines = ( SCREEN WIDTH / cardWidth ) + 1
POSITIVE CONST cardXMax = verticalLines - 1
POSITIVE CONST horizontalLines = ( SCREEN HEIGHT / cardHeight ) + 1
POSITIVE CONST cardYMax = horizontalLines - 1
POSITIVE CONST cardEffectiveWidth = cardWidth - 2
POSITIVE CONST cardEffectiveHeight = cardHeight - 2

' DIM colors(16) = #{ _
' 			BLACK, WHITE, BROWN, LAVENDER, LIGHT BLUE, LIGHT GREEN, LIGHT RED, OLIVE GREEN, _
' 			PEACH, PINK, VIOLET, DARK BLUE, TAN, MAGENTA, TURQUOISE, YELLOW GREEN _
' 		 }

' DIM primary(16) = #{ _
' 			DARK RED, RED, LIGHT RED, DARK BLUE, BLUE, LIGHT BLUE, WHITE, BLACK, _
' 			DARK GREEN, GREEN, LIGHT GREEN, WHITE, TAN, TURQUOISE, YELLOW GREEN, WHITE _
' 		 }

DIM primary2(16) = #{ _
			DARK RED, RED, LIGHT RED, DARK BLUE, BLUE, LIGHT BLUE, WHITE, BLACK, _
			DARK GREEN, GREEN, LIGHT GREEN, WHITE, BROWN, LAVENDER, OLIVE GREEN, WHITE _
		 }

PROCEDURE drawLines

	DIM lineIndex AS BYTE

	FOR lineIndex = 1 TO ( horizontalLines - 1 )
		LINE 0, lineIndex * cardHeight TO (SCREEN WIDTH - 1), lineIndex * cardHeight, cardColor
	NEXT lineIndex

	FOR lineIndex = 1 TO ( verticalLines - 1 )
		LINE lineIndex * cardWidth, 0 TO lineIndex * cardWidth, (SCREEN HEIGHT - 1),  cardColor
	NEXT lineIndex

END PROCEDURE

PROCEDURE drawColors

	' SHARED colors, primary, primary2
	SHARED primary2

	DIM colorIndex AS BYTE
	DIM cardX1 AS POSITION
	DIM cardY1 AS POSITION
	DIM cardX2 AS POSITION
	DIM cardY2 AS POSITION

	cardX1 = cardWidth + 1
	cardY1 = 1
	cardX2 = cardX1 + cardEffectiveWidth
	cardY2 = cardY1 + cardEffectiveHeight

	FOR colorIndex = 0 TO UBOUND( primary2 ) - 1

		IF colorIndex = 8 THEN
			cardX1 = cardWidth + 1
			cardX2 = cardX1 + cardEffectiveWidth
			ADD cardY1, cardHeight
			ADD cardY2, cardHeight
		ENDIF

		IF colorIndex = 0 OR colorIndex = 8 THEN
			LOCATE 0, ( cardY1 / FONT HEIGHT ) + 1 : PRINT " COLORS "
		ENDIF

		BAR cardX1, cardY1 TO cardX2, cardY2, primary2( colorIndex )
		ADD cardX1, cardWidth
		ADD cardX2, cardWidth

	NEXT

END PROCEDURE

PROCEDURE drawGreys

	DIM cardX1 AS POSITION
	DIM cardY1 AS POSITION
	DIM cardX2 AS POSITION
	DIM cardY2 AS POSITION

	cardY1 = 3*cardHeight + 1
	cardX1 = 2*cardWidth + 1
	cardY2 = cardY1 + cardHeight - 2
	cardX2 = cardX1 + cardEffectiveWidth

	LOCATE 0, ( cardY1 / FONT HEIGHT ) + 1 : PRINT " GREY"
	BAR cardX1, cardY1 TO cardX2, cardY2, DARK GREY
	ADD cardX1, cardWidth
	ADD cardX2, cardWidth

	BAR cardX1, cardY1 TO cardX2, cardY2, GREY
	ADD cardX1, cardWidth
	ADD cardX2, cardWidth

	BAR cardX1, cardY1 TO cardX2, cardY2, LIGHT GREY
	ADD cardX1, cardWidth
	ADD cardX2, cardWidth

	cardX1 = 3*cardWidth + 1
	cardX2 = cardX1 + cardEffectiveWidth
	ADD cardY1, cardHeight
	ADD cardY2, cardHeight

	LOCATE 0, ( cardY1 / FONT HEIGHT ) + 1 : PRINT " WHITE"
	BAR cardX1, cardY1 TO cardX2, cardY2, DARK WHITE
	ADD cardX1, cardWidth
	ADD cardX2, cardWidth

	BAR cardX1, cardY1 TO cardX2, cardY2, WHITE
	ADD cardX1, cardWidth
	ADD cardX2, cardWidth

	BAR cardX1, cardY1 TO cardX2, cardY2, LIGHT WHITE
	ADD cardX1, cardWidth
	ADD cardX2, cardWidth

END PROCEDURE

PROCEDURE drawMonoscope

	CIRCLE SCREEN WIDTH / 2, SCREEN HEIGHT / 2, MIN( SCREEN WIDTH / 2, SCREEN HEIGHT / 2 ), cardColor

END PROCEDURE

drawLines[]
drawColors[]
drawGreys[]
drawMonoscope[]

