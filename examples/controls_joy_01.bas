REM @english
REM I/O CONTROL WITH JOYSTICK (1)
REM
REM This example will read the joystick status for the first joystick. Then it will decode the
REM value in a binary string and print it on the screen. This example also shows how 
REM automatic scrolling works, when the end of the screen is reached with the
REM use of the ''PRINT'' command.
REM
REM @italian
REM CONTROLLI DI I/O CON IL JOYSTICK (1)
REM
REM Questo esempio leggerà lo status del primo joystick. Quindi ne decodificherà il valore
REM in una stringa binaria, e lo mostrerà sullo schermo. Questo esempio inoltre mostra come
REM funziona lo scrolling verticale automatico, quando si raggiunge  con l'uso del comando 
REM ''PRINT'' la fine dello schermo.
REM

    DO
        j=JOY(0)
        PRINT BIN$(j,5),j
    LOOP
