REM @english
REM MULTI TASKING ACCESSING VARIABLES (IMPLICIT)
REM
REM This example will show how to use a separate variable for each task. This is the implicit
REM way to access, using the ''[...]'' operator.
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (4)
REM
REM Questo esempio mostrerà come usare variabili separate per ogni task. Questo è l'approccio
REM implicito per accedere, usando l'operatore ''[...]''.
REM
REM @include atari,atarixl,c128,c64,coco,coleco

    DIM x WITH 0 (3)
    GLOBAL x

    PARALLEL PROCEDURE accessing
        DO
            [x] = [x] + 1
            PRINT [x];" ";
        LOOP
    END PROC

    SPAWN accessing
    SPAWN accessing
    SPAWN accessing

    CLS
    
