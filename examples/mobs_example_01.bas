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

SCREEN #3

airplaneImage = IMAGE LOAD("examples/checkers.png")
airplane1 = 1
MOB airplane1, airplaneImage
MOB SHOW airplane1
i = (POSITION) 0
FOR i = (POSITION) 0 TO (POSITION) 50 STEP (POSITION) 1
    MOB airplane1 AT (POSITION) 0, i
    MOB RENDER
    WAIT KEY
NEXT
FOR i = (POSITION) 0 TO (POSITION) 50 STEP (POSITION) 1
    MOB airplane1 AT i, (POSITION) 50
    MOB RENDER
    WAIT KEY
NEXT
HALT

' airplaneImage = IMAGE LOAD("examples/checkers.png")
' airplane1 = 1
' MOB airplane1, airplaneImage
' MOB SHOW airplane1
' i = (POSITION) 0
' FOR i = (POSITION) 0 TO (POSITION) 200 STEP (POSITION) 4
'     MOB airplane1 AT (POSITION) 0, i
'     MOB RENDER
'     WAIT KEY
' NEXT
' HALT


' sh = SCREEN HEIGHT / 4

' airplaneImage = IMAGE LOAD("examples/air_attack_airplane.png")
' airplane1 = 1
' airplane2 = 2
' airplane3 = 3

' MOB airplane1, airplaneImage
' MOB airplane2, airplaneImage
' MOB airplane3, airplaneImage

' x = 0

' MOB SHOW airplane1
' MOB SHOW airplane2
' MOB SHOW airplane3
' DO
'     MOB airplane1 AT x,sh
'     MOB airplane2 AT x,2*sh
'     MOB airplane3 AT x,4*sh
'     x = x + 1
'     MOB RENDER
' LOOP
