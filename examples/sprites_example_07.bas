REM @english
REM SPRITE MANAGEMENT COLLISIONS (2)
REM
REM This example shows how to check a collision with multicolor sprites.
REM
REM @italian
REM GESTIONE DEGLI SPRITE COLLISIONI (2)
REM
REM Questo esempio mostra come verificare una collisione con sprite multicolore.

BITMAP ENABLE (16)

ballImage = LOAD IMAGE("sprite_ball_color.png")
basketImage = LOAD IMAGE("sprite_basket_color.png")

ball = CSPRITE(ballImage)
basket = CSPRITE(basketImage)

SPRITE basket AT 100,100 ENABLE
SPRITE ball AT 50, 101 ENABLE

COLOR BORDER RED

FOR i = 1 TO 160
    SPRITE ball AT i, 101
    IF COLLISION(basket) THEN
        COLOR BORDER YELLOW
    ELSE
        COLOR BORDER BLACK
    ENDIF
    WAIT 50 MS
NEXT
