REM @english
REM SPRITE MANAGEMENT TESTING COLLISION
REM
REM This example shows how to test collisions.
REM
REM @italian
REM GESTIONE DEGLI SPRITE TESTARE LE COLLISIONI
REM
REM Questo esempio mostra come provare le collisioni.
REM
REM @include coleco

BITMAP ENABLE (16)

spriteImage = LOAD IMAGE("sprite.png")

sprite1 = SPRITE(spriteImage)
sprite2 = SPRITE(spriteImage)

SPRITE sprite1 ENABLE
SPRITE sprite2 ENABLE

SPRITE sprite1 AT 50,100 COLOR YELLOW

FOR x=0 TO 100
    SPRITE sprite2 AT x,100 COLOR RED
    WAIT KEY
    IF COLLISION(sprite1) THEN
        LOCATE 0,0 : PRINT "ok!"
    ENDIF
NEXT
