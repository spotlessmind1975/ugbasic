REM @english
REM MULTI TASKING PRE-EMPTIVE PARALLEL COMPUTING
REM
REM This example will draw, separately, the four angles of a square.
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (5)
REM
REM Questo esempio disegnerà, separatamente, i quattro angoli di un quadrato.
REM
REM @url https://www.facebook.com/groups/28618623481/posts/10159544654308482/
REM
REM @include atari,atarixl,c128

    BITMAP ENABLE (16)

    POSITIVE CONST limit = MIN( SCREEN WIDTH-1, SCREEN HEIGHT-1 )

    CLS

    PARALLEL PROCEDURE proc1
        FOR x=0 TO limit STEP 10
            DRAW 0,x TO x,limit
        NEXT
    END PROC

    PARALLEL PROCEDURE proc2
        FOR x=0 TO limit STEP 10
            DRAW x,0 TO 0,limit-x
        NEXT
    END PROC

    PARALLEL PROCEDURE proc3
        FOR x=0 TO limit STEP 10
            DRAW x,0 TO limit,x
        NEXT
    END PROC

    PARALLEL PROCEDURE proc4
        FOR x=0 TO limit STEP 10
            DRAW x,limit TO limit,limit-x
        NEXT
    END PROC

    SPAWN proc1
    SPAWN proc2
    SPAWN proc3
    SPAWN proc4
