REM @english
REM FLOW CONTROL USING SELECT CASE
REM
REM This example will show how to use the ''SELECT CASE'' instruction.
REM 
REM @italian
REM CONTROLLO DI FLUSSO CON SELEZIONE MULTIPLA
REM
REM Questo esempio mostra come usare il comando ''SELECT CASE''.
REM
REM @include atari,atarixl

    CLS

    DO

        INPUT "Digit a number between 0 and 5: ";number

        PRINT

        PRINT "The number is ";

        SELECT CASE number
            CASE 0
                PRINT "zero!"
            CASE 1
                PRINT "odd"
            CASE 2
                PRINT "even"
            CASE 3
                PRINT "odd"
            CASE 4
                PRINT "even"
            CASE 5
                PRINT "odd"
            CASE ELSE
                PRINT "greater than 5!"
        ENDSELECT

        PRINT

    LOOP