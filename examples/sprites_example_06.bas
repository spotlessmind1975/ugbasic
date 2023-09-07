REM @english
REM SPRITE MANAGEMENT COLLISIONS (1)
REM
REM This example shows how to check a collision with monocolor sprites.
REM
REM @italian
REM GESTIONE DEGLI SPRITE COLLISIONI (1)
REM
REM Questo esempio mostra come verificare una collisione con sprite monocolori.
REM
REM @include coleco

BITMAP ENABLE (2)

ballImage = LOAD IMAGE("sprite_ball.png")
basketImage = LOAD IMAGE("sprite_basket.png")

ball = SPRITE(ballImage)
basket = SPRITE(basketImage)

SPRITE basket AT 100,100 ENABLE
SPRITE ball AT 50, 101 ENABLE

COLOR BORDER BLACK

FOR i = 1 TO 160
    SPRITE ball AT i, 101
    IF COLLISION(basket) THEN
        COLOR BORDER YELLOW
    ELSE
        COLOR BORDER BLACK
    ENDIF
    WAIT 50 MS
NEXT
