REM @english
REM MULTI TASKING FOR DUMMIES (5)
REM
REM This example will draw, separately, the four angles of a square.
REM This example has been taken from [[https://www.facebook.com/groups/28618623481/posts/10159544654308482/|this post]] by Dino Florenzi.
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (5)
REM
REM Questo esempio disegnerà, separatamente, i quattro angoli di un quadrato.
REM Questo esempio è stato preso da [[https://www.facebook.com/groups/28618623481/posts/10159544654308482/|questo post]] by Dino Florenzi.

BITMAP ENABLE (16)
CLS

PARALLEL PROCEDURE proc1
    FOR x=0 TO 199 STEP 10
        DRAW 0,x TO x,199
    NEXT
END PROC

PARALLEL PROCEDURE proc2
    FOR x=0 TO 199 STEP 10
        DRAW x,0 TO 0,199-x
    NEXT
END PROC

PARALLEL PROCEDURE proc3
    FOR x=0 TO 199 STEP 10
        DRAW x,0 TO 199,x
    NEXT
END PROC

PARALLEL PROCEDURE proc4
    FOR x=0 TO 199 STEP 10
        DRAW x,199 TO 199,199-x
    NEXT
END PROC

SPAWN proc1
SPAWN proc2
SPAWN proc3
SPAWN proc4

DO:RUN PARALLEL:LOOP