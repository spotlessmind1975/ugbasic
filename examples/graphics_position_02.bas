REM @english
REM GRAPHICS PRIMITIVES USIGN POSITION (2)
REM
REM This example will show how to obtain current graphic position,
REM using the ''XGR'' and ''YGR'' variables.
REM
REM @italian
REM PRIMITIVE DI GRAFICA PER POSIZIONE 2)
REM
REM Questo esempio mostra come ricavare la posizione grafica corrente,
REM utilizzando le variabili ''XGR'' e ''YGR''.

    BITMAP ENABLE
    CLS
    CIRCLE 100,100,50
    PRINT XGR,YGR

    HALT