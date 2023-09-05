REM @english
REM GRAPHICS PRIMITIVES USING PALETTE
REM
REM This example will show how to use the palette command.
REM
REM @italian
REM PRIMITIVE DI GRAFICA USARE LA PALETTE
REM
REM Questo esempio mostra come usare il comando del impostare la palette delle sfumature.
REM
REM @include atari,atarixl,c128

    BITMAP ENABLE(16)
    CLS BLACK
    PALETTE RGB($00,$00,$00), RGB($11,$11,$11), RGB($22,$22,$22), RGB($33,$33,$33), _
            RGB($44,$44,$44), RGB($55,$55,$55), RGB($66,$66,$66), RGB($77,$77,$77), _
            RGB($88,$88,$88), RGB($99,$99,$99), RGB($AA,$AA,$AA), RGB($BB,$BB,$BB), _
            RGB($CC,$CC,$CC), RGB($DD,$DD,$DD), RGB($EE,$EE,$EE), RGB($FF,$FF,$FF)

    FOR x = 0 TO SCREEN WIDTH - 1
        color = ( x / ( SCREEN WIDTH / SCREEN COLORS ) )
        FOR y = 0 TO ( SCREEN HEIGHT - 1 )
            PLOT x, y, color
        NEXT 
    NEXT