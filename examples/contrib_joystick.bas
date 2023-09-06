REM @english
REM OTHER CONTRIBUTIONS JOYSTICK PRIZE TRIBUTE
REM
REM This example represents a tribute to the Facebook group Retroprogramming Italia, 
REM following the victory in the "FORZA 4 Challenge".
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI SPEED TEST DI IF
REM
REM Questo esempio rappresenta un tributo al gruppo Facebook Retroprogramming Italia, 
REM a seguito della vittoria nella "FORZA 4 Challenge". 
REM
REM @include atari,atarixl

    BITMAP ENABLE(16)
    CLS BLACK
    COLOR BORDER BLACK
    INK WHITE

    CONST w = SCREEN COLUMNS - 5
    CONST h2 = IF(SCREEN ROWS > 24, 2, 1)
    CONST hc = SCREEN ROWS / 2

    joystick := LOAD IMAGE("joystick4.png")

    LOCATE 0,hc - 2: CENTER "A TUTTO IL GRUPPO DI"
    LOCATE 0, hc - 1: CENTER "RetroProgramming"
    LOCATE 0, hc: CENTER "Italia"
    LOCATE 0,hc + 1: CENTER "RP Italia"
    LOCATE 0,hc + 3: CENTER "A division of"
    LOCATE 0,hc + 4: CENTER "RetroCampus"

    WAIT KEY

    CLS BLACK

    PUT IMAGE joystick AT 0,0

    LOCATE w, h2: PRINT "G";: WAIT 1000 MS
    LOCATE w+2, 2*h2: PRINT "R";: WAIT 1000 MS
    LOCATE w, 3*h2: PRINT "A";: WAIT 1000 MS
    LOCATE w+2, 4*h2: PRINT "Z";: WAIT 1000 MS
    LOCATE w, 5*h2: PRINT "I";: WAIT 1000 MS
    LOCATE w+2, 6*h2: PRINT "E";: WAIT 1000 MS

    LOCATE w, 7*h2: PRINT "G";: WAIT 1000 MS
    LOCATE w+2, 8*h2: PRINT "R";: WAIT 1000 MS
    LOCATE w, 9*h2: PRINT "A";: WAIT 1000 MS
    LOCATE w+2, 10*h2: PRINT "Z";: WAIT 1000 MS
    LOCATE w, 11*h2: PRINT "I";: WAIT 1000 MS
    LOCATE w+2, 12*h2: PRINT "E";: WAIT 1000 MS
