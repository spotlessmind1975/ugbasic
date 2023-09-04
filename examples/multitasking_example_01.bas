REM @english
REM MULTI TASKING SIMPLE CONCURRENCY (2 TASKS)
REM
REM This is a very simple example. We will run two separates tasks:
REM the first will print the "first" string, while the second will
REM print the "second". Since the two tasks are running at the
REM same time on the processor, the two strings are printed alternatively.
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (1)
REM
REM Questo è un esempio molto semplice. Eseguiremo due task separati: il 
REM primo stamperà la stringa "first", mentre il secondo stamperà "second". 
REM Poiché le due attività sono in esecuzione contemporaneamente sul processore, 
REM le due stringhe vengono stampate alternativamente.
REM
REM @include atari,atarixl

    PARALLEL PROCEDURE printFirst
        DO
            PRINT "first"
        LOOP
    END PROC

    PARALLEL PROCEDURE printSecond
        DO
            PRINT "second"
        LOOP
    END PROC

    SPAWN printFirst
    SPAWN printSecond

    CLS
    