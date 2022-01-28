REM @english
REM MULTI TASKING FOR DUMMIES (6)
REM
REM This example will show how to use multitasking to
REM make a simple animation of various bats on the
REM screen.
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (6)
REM
REM Questo esempio mostrerà come usare il multitasking per
REM realizzare una semplice animazione di vari pipistrelli
REM sullo schermo.

BITMAP ENABLE (16)
CLS BLACK

bat := LOAD IMAGES("examples/bat.png" ) FRAME SIZE (32,32)

CONST POSITIVE batCount = 4

DIM x(batCount)
DIM y(batCount)
DIM f(batCount)

PARALLEL PROCEDURE moveBat
    SHARED bat, x, y, f
    DO
        PUT IMAGE bat FRAME [f] AT [x],[y]
        [f] = [f] + 1
        IF [f] == FRAMES(bat) THEN
            [f] = 0
        ENDIF
    LOOP
END PROC

FOR i=0 TO (batCount-1)
    x(i) = i * (SCREEN WIDTH / batCount)
    y(i) = i * (SCREEN HEIGHT / batCount)
    f(i) = i MOD (batCount-1)
    SPAWN moveBat
NEXT

DO: RUN PARALLEL: LOOP
