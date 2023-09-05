REM @english
REM OTHER CONTRIBUTIONS MAZE GENERATOR
REM
REM Generation of random mazes via backtracking. This program is a port of the example 
REM written in XC=BASIC 3.1 by JJ Flash, with the addition of a "mouse" that moves 
REM inside the maze in search of the "cheese".
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI GENERATORE DI LABIRINTI
REM
REM Generazione di labirinti casuali tramite backtracking. Questo programma ? un porting 
REM dall'esempio scritto in XC=BASIC 3.1 da parte di JJ Flash, con l'aggiunta di un 
REM "topolino" che si muove all'interno del labirinto in cerca del "formaggio".
REM
REM @include c128

DEFINE DEFAULT TYPE SIGNED WORD

VAR finalScrPosition AS WORD

CONST wall = 95 : CONST space = 32 : CONST mouse = 81

VAR nextDirection AS BYTE: VAR firstnextDirection AS BYTE

DIM dirArray(4) = #{ 2, -80, -2, 80 }

PRINT "press a key (i need randomness)"
WAIT KEY

CLS BLACK
INK WHITE

RANDOMIZE TIMER

restart:
FOR i = 0 TO 999: POKE Txa+i, wall: NEXT
FOR i = 0 TO 39: POKE Txa+i, space: NEXT
FOR i = 0 TO 39: POKE Txa+984+i,space: NEXT

screenPosition = Txa+79
FOR i = 1 TO 23
    POKE screenPosition, space
    screenPosition = screenPosition + 40
NEXT

steps = 0 : maxSteps = 0

screenPosition = Txa + 81 + (80 * RND(9)) + 2 * RND(9)

POKE screenPosition, 4 : ' "D"

digAnotherLocation:
    nextDirection = RND(3) : firstnextDirection = nextDirection
    IF steps > maxSteps THEN : maxSteps = steps: finalScrPosition = newScreenPosition : ENDIF

tryDiggingAgain:
    newScreenPosition = screenPosition + dirArray(nextDirection)
    IF PEEK(newScreenPosition) = wall THEN
        POKE newScreenPosition, nextDirection
        POKE screenPosition + ( dirArray(nextDirection)\2 ), space
        screenPosition = newScreenPosition
        steps = steps + 1
        GOTO digAnotherLocation
    ENDIF

    nextDirection = (nextDirection + 1) AND 3
    IF nextDirection <> firstnextDirection THEN : GOTO tryDiggingAgain : ENDIF
    
    nextDirection = PEEK(screenPosition) : POKE screenPosition, space
    steps = steps - 1
    IF nextDirection < 4 THEN
        screenPosition = screenPosition - dirArray(nextDirection)
        GOTO digAnotherLocation
    ENDIF
    
    POKE screenPosition, 1 : POKE finalScrPosition, 2
    HOME : PRINT "max steps: " ; maxSteps ; " - final loc: " ; finalScrPosition
    
    POKE screenPosition, mouse : nextDirection = 2
mouseLabel:
    WAIT VBL
    newScreenPosition = screenPosition + (dirArray(nextDirection)\2)
    IF newScreenPosition = finalScrPosition THEN : GOTO restart : ENDIF
    IF PEEK(newScreenPosition) = space THEN
        POKE newScreenPosition, mouse : POKE screenPosition, space
        screenPosition = newScreenPosition
        nextDirection = (nextDirection - 2) AND 3
    ENDIF
    nextDirection = (nextDirection - 1) AND 3
    GOTO mouseLabel

