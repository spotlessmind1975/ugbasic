REM @english
REM STATIC IMAGES IMAGE CAPURE (USING GET IMAGE AND PALETTE)
REM
REM This example will show how to capture an image from
REM the screen after putting it. It answers to bug #367.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI CATTURA (2)
REM
REM Questo piccolo esempio mostra come catturare una immagine
REM dallo schermo dopo averla disegnata. Risponde al bug #367.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,cpc

    BITMAP ENABLE (160,200,16)
    'Palette
    PALETTE RGB(0,0,0),RGB(255,0,0),RGB(255,255,0),RGB(255,255,0), _
        RGB(0,0,255),RGB(255,0,255),RGB(0,255,255),RGB(255,255,255), _
        RGB(187,187,187),RGB(221,119,119),RGB(119,221,119)
    '
    tile1 := LOAD IMAGE("drop.png")
    '
    DOUBLE BUFFER ON
    '
    CLS BLACK
    PUT IMAGE tile1 AT 80, 100
    SCREEN SWAP
    PUT IMAGE tile1 AT 80, 100
    SCREEN SWAP
    '
    plrBG := NEW IMAGE(16,16)
    DO
        GET IMAGE plrBG FROM 80, 100
        PUT IMAGE plrBG AT 80, 100
        SCREEN SWAP
    LOOP
