REM @english
REM MULTI TASKING CONDITIONATED CONCURRENCY (WAIT FOR ENDING TASK)
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
REM attività prima di continuare. Questa è una forma molto semplice di sincronismo.
REM
REM @include atari,atarixl,c128,c64

    GLOBAL t

    PARALLEL PROCEDURE secondaryTask
        FOR x = 1 TO 10
            PRINT "primary: ";x
        NEXT
    END PROC

    PARALLEL PROCEDURE primaryTask
        WAIT PARALLEL SPAWN secondaryTask
        PRINT "secondary"
    END PROC

    SPAWN primaryTask

    CLS
    