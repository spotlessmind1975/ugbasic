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

    DOUBLE BUFFER ON
    CLS
    SCREEN SWAP
    CLS
    SCREEN SWAP

    anim := LOAD IMAGES("ponyo2.gif") FRAME SIZE AUTO

    DO
        PUT IMAGE anim FRAME frame AT 0, 0
        PUT IMAGE anim FRAME frame AT 32, 0
        PUT IMAGE anim FRAME frame AT 0, 32
        PUT IMAGE anim FRAME frame AT 32, 32
        WAIT VBL
        SCREEN SWAP
        ADD frame, 1, 0 TO FRAMES(anim)-1
    LOOP