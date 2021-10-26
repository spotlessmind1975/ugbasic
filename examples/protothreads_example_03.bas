REM @english
REM MULTI TASKING FOR DUMMIES (3)
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (3)
REM

    GLOBAL t

    PARALLEL PROCEDURE example1
        FOR x = 1 TO 10
            PRINT "example ";x
            YIELD
        NEXT
    END PROC

    PARALLEL PROCEDURE example2
        t = INVOKE example1
        WAIT PARALLEL t
        PRINT "example2"
    END PROC

    INVOKE example2

   DO
        RUN PARALLEL
   LOOP

   HALT
