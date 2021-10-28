REM @english
REM MULTI TASKING FOR DUMMIES (1)
REM
REM This is a very simple example. We will run two separates tasks:
REM the first will print the "example" string, while the second will
REM print the "example2". Since the two tasks are running at the
REM same time on the processor, the two strings are printed alternatively.
REM
REM @italian
REM USARE IL MULTITASKING CON UN ESEMPIO (1)
REM
REM Questo è un esempio molto semplice. Eseguiremo due task separati: il 
REM primo stamperà la stringa "example", mentre il secondo stamperà "example2". 
REM Poiché le due attività sono in esecuzione contemporaneamente sul processore, 
REM le due stringhe vengono stampate alternativamente.

    PARALLEL PROCEDURE example1
        DO
            PRINT "example"
        LOOP
    END PROC

    PARALLEL PROCEDURE example2
        DO
            PRINT "example2"
        LOOP
    END PROC

    SPAWN example1
    SPAWN example2

    DO
        RUN PARALLEL
    LOOP

    HALT
