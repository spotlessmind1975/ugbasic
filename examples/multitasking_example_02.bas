REM @english
REM MULTI TASKING FOR DUMMIES (2)
REM
REM This example will show how to invoke a task inside another task, and
REM how to wait the end of execution of the second task before continue.
REM This is a very simple form of synchronism.
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (2)
REM
REM Questo esempio mostrerà come richiamare un'attività all'interno di 
REM un'altra attività e come attendere la fine dell'esecuzione della seconda 
REM attività prima di continuare. Questa è una forma molto semplice di s
REM incronismo.

    GLOBAL t

    PARALLEL PROCEDURE example1
        FOR x = 1 TO 10
            PRINT "example ";x
        NEXT
    END PROC

    PARALLEL PROCEDURE example2
        WAIT PARALLEL SPAWN example1
        PRINT "example2"
    END PROC

    SPAWN example2

    DO
         RUN PARALLEL
    LOOP

    HALT
