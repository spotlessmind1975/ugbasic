REM @english
REM GRAPHICS PRIMITIVES USING DOUBLE BUFFER
REM
REM This example will show how to use the double buffering.
REM
REM @italian
REM PRIMITIVE DI GRAFICA USARE IL DOUBLE BUFFERING
REM
REM Questo esempio mostra come usare il double buffering.
REM

    BITMAP ENABLE (320,200,16)

    image := NEW IMAGE( 32, 32 )
    BAR 0, 0 TO 32, 32, RED
    GET IMAGE image FROM 0, 0

    DOUBLE BUFFER ON
    CLS BLACK
    SCREEN SWAP
    CLS BLACK
    SCREEN SWAP

    DIM x AS POSITION, y AS POSITION
    DIM dx AS POSITION, dy AS POSITION

    x = 0: y = 0
    dx = 1: dy = 1

    DO
        ADD x, dx
        ADD y, dy

        IF ( x > (SCREEN WIDTH-11) ) OR ( x < 1 ) THEN
            dx = -dx
        ENDIF
        IF ( y > (SCREEN HEIGHT-11) ) OR ( y < 1 ) THEN
            dy = -dy
        ENDIF

        PUT IMAGE image AT x, y
        WAIT VBL
        SCREEN SWAP
    LOOP