REM @english
REM STATIC IMAGES LOADING MULTICOLOR IMAGE ( USING PRINT )
REM
REM This small example will show how to load a PNG image file as a static multicolor ''IMAGE''.
REM 
REM @italian
REM GESTIONE DELLE IMMAGINI CARICAMENTO (2)
REM
REM Questo piccolo esempio mostra come caricare una piccola PNG come immagine multicolore statica.
REM
REM @include atari

    BITMAP ENABLE (16)
    CLS

    airplane = LOAD IMAGE("air_attack_airplane.png" )

    PRINT airplane
