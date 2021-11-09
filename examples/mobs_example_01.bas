REM @english
REM MOVING IMAGES USING MOBS (1)
REM
REM This small example will show how to use MOBS to implement moving objects.
REM 
REM @italian
REM IMMAGINI IN MOVIMENTO USARE I MOBS (1)
REM
REM Questo piccolo esempio mostra come usare i MOB per implementare oggetti in movimento.
REM

BITMAP ENABLE (2)

airplaneImage = IMAGE LOAD("examples/air_attack_airplane.png")

h = SCREEN HEIGHT - IMAGE HEIGHT(airplaneImage)
w = SCREEN WIDTH - IMAGE WIDTH(airplaneImage)

airplane1 = MOB(airplaneImage)
MOB SHOW airplane1
MOB RENDER ON VBL
WAIT KEY
i = (POSITION) 0
FOR i = (POSITION) 0 TO h STEP (POSITION) 1
    MOB airplane1 AT (POSITION) 0, i
    MOB RENDER ON VBL
    WAIT KEY
NEXT
FOR i = (POSITION) 0 TO  w STEP (POSITION) 1
    MOB airplane1 AT i, h
    MOB RENDER ON VBL
    WAIT KEY
NEXT
HALT
