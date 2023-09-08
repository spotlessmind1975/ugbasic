REM @english
REM USER-DEFINED PROCEDURES CALL A PROCEDURE (USING ON...PROC)
REM
REM This small example will use the ''ON...PROC'' keywords to implement
REM a endless loop, printing the digits "1", "2" and "3". The current
REM number to print will be stored into the ''times'' variable.
REM This example also shows how automatic scrolling works, when the end 
REM of the screen is reached with the use of the ''PRINT'' command.
REM 
REM @italian
REM USARE LE PROCEDURE CON IL CONTROLLO DEL FLUSSO (1)
REM
REM Questo piccolo esempio utilizza le istruzioni ''ON...PROC''
REM per implementare un loop senza fine, stampando le cifre "1", "2" e
REM "3". Il numero da stampare sarà quello memorizzato nella variabile
REM ''times''. Questo esempio mostra inoltre il funzionamento dello scrolling
REM automatico, quando si raggiunge con l'uso del comando ''PRINT'' la fine dello schermo.
REM
REM @include atari,atarixl,c128,c64,coco,coleco,cpc

    CLS
   
    PROCEDURE first
        PRINT 1;" ";
    END PROC

    PROCEDURE second
        PRINT 2;" ";
    END PROC

    PROCEDURE third
        PRINT 3;" ";
    END PROC

    times = 1
start:
    ON times PROC first, second, third
    times = times + 1
    IF times > 3 THEN
        times = 1
    ENDIF
    GOTO start
