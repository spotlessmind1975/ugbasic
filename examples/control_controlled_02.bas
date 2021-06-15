REM @english
REM FLOW CONTROL BY CONTROLLED LOOPS (2)
REM
REM This small example will use the ''FOR...NEXT'' keywords to implement
REM a "nested" loop. The inner loop will count from 1 to 5, while the outer
REM one will count from 1 to 100. So it will print first 1, 2, 3, 4, 5; then,
REM it will print 2, 4, 6, 8, 10; and so on. This example also shows how 
REM automatic scrolling works, when the end of the screen is reached with the
REM use of the ''PRINT'' command.
REM 
REM @italian
REM CONTROLLO DI FLUSSO CON LOOP CONTROLLATI (2)
REM
REM Questo piccolo esempio utilizza le istruzioni ''FOR...NEXT''
REM per implementare due loop innestati. Quello più interno conta da 1 a 5,
REM mentre quello più esterno da 1 a 100. Quindi stamperà prima 1, 2, 3, 4, 5;
REM dopo di che stamperà 2, 4, 6, 8, 10; e così via. Questo esempio mostra 
REM inoltre il funzionamento dello scrolling automatico, quando si raggiunge 
REM con l'uso del comando ''PRINT'' la fine dello schermo.
REM

    i = 0 : j = 0
    FOR i = 1 TO 100
        FOR j = 1 TO 5
            PRINT (i * j);" ";
        NEXT
    NEXT

    HALT