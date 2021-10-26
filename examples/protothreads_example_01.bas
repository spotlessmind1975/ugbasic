REM @english
REM MULTI TASKING FOR DUMMIES (1)
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (1)
REM

    PARALLEL PROCEDURE example1
        x = 0
        DO
            PRINT "example";x
            YIELD
            INC x
        LOOP
    END PROC

    PARALLEL PROCEDURE example2
        DO
            PRINT "example2"
            YIELD
        LOOP
    END PROC

   INVOKE example1
   INVOKE example2

   DO
        RUN PARALLEL
   LOOP

   HALT
