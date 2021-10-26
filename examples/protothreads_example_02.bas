REM @english
REM MULTI TASKING FOR DUMMIES (2)
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (2)
REM

    GLOBAL t

    PARALLEL PROCEDURE example1
        FOR x = 1 TO 100
            PRINT "example ";x
            YIELD
        NEXT
    END PROC

    PARALLEL PROCEDURE example2
        WAIT PARALLEL t
        PRINT "example2"
    END PROC

   t = INVOKE example1
   INVOKE example2

   DO
        RUN PARALLEL
   LOOP

   HALT
