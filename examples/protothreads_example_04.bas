REM @english
REM MULTI TASKING FOR DUMMIES (4)
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (4)
REM

    DIM x WITH 0 (3), i WITH 0 (3)
    GLOBAL x, i

    PARALLEL PROCEDURE example
        DO
            PRINT "*";THREAD;"*"
            x(THREAD) = x(THREAD) + 1
            PRINT x(THREAD);" ";
            YIELD
        LOOP
    END PROC

    SPAWN example
    SPAWN example
    SPAWN example

   DO
        RUN PARALLEL
   LOOP

   HALT
