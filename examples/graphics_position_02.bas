REM @english
REM GRAPHICS PRIMITIVES POSITIONING (USING XGR AND YGR)
REM
REM This example will show how to obtain current graphic position,
REM using the ''XGR'' and ''YGR'' variables.
REM
REM @italian
REM PRIMITIVE DI GRAFICA PER POSIZIONE 2)
REM
REM Questo esempio mostra come ricavare la posizione grafica corrente,
REM utilizzando le variabili ''XGR'' e ''YGR''.
REM
REM @include atari,atarixl,c128

    BITMAP ENABLE
    CLS
    CIRCLE SCREEN WIDTH / 2, SCREEN HEIGHT / 2, 42
    PRINT XGR,YGR
