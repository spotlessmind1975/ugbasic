REM @english
REM MULTI TASKING ACCESSING VARIABLES (EXPLICIT)
REM
REM This example will show how to use a separate variable for each task. This is the explicit
REM way to access, using the ''TASK'' number as an "index" inside a dedicated array.
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (3)
REM
REM Questo esempio mostrerà come usare variabili separate per ogni task. Questa è la forma
REM esplicita per accedere, che usa la variabile di sistema ''TASK'' come "indice" in un 
REM vettore dedicato.
REM
REM @include atari,atarixl,c128,c64

    DIM x WITH 0 (3)
    GLOBAL x

    PARALLEL PROCEDURE accessing
        DO
            x(TASK) = x(TASK) + 1
            PRINT TASK;") value = "; x(TASK);" "
        LOOP
    END PROC

    SPAWN accessing
    SPAWN accessing
    SPAWN accessing

    CLS
