REM @english
REM STATIC IMAGES DISPLAY AN (Y DOUBLED) RED TOKEN (USING PUT IMAGE)
REM
REM This small example will show how to load and draw a PNG image on a colored bitmap screen.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI DISEGNO (2)
REM
REM Questo piccolo esempio mostra come caricare una piccola PNG e disegnarla sulla bitmap colorata.
REM
REM @include c128,coleco

    BITMAP ENABLE (4)
    CLS

    tokenImage = LOAD IMAGE("token_red.png")

    PUT IMAGE tokenImage AT 0, 0 DOUBLE Y