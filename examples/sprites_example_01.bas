REM @english
REM SPRITE MANAGEMENT CREATE A (SIMPLE) SPRITE
REM
REM This example shows how to create a simple "sprite", a monocolor
REM object that can be moved freely on the screen.
REM
REM @italian
REM GESTIONE DEGLI SPRITE CREARE UN (SEMPLICE) SPRITE
REM
REM Questo esempio mostra come creare un semplice "sprite", un ogggetto
REM monocolore che può essere mosso liberamente sullo schermo.

BITMAP ENABLE (16)

spriteImage = LOAD IMAGE("examples/sprite.png")

sprite = SPRITE(spriteImage)

SPRITE sprite ENABLE

FOR x=0 TO 100
    SPRITE sprite AT x,100 COLOR RED
    WAIT KEY
NEXT
