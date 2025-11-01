REM @english
REM I/O CONTROL JOYSTICK READ (BITMAP)
REM
REM This example will read the joystick status for the first joystick. Then it will decode the
REM value in a binary string and print it on the screen. This example also shows how 
REM automatic scrolling works, when the end of the screen is reached with the
REM use of the ''PRINT'' command.
REM
REM @italian
REM CONTROLLI DI I/O LETTURA JOYSTICK (MAPPA DI BIT)
REM
REM Questo esempio leggerà lo status del primo joystick. Quindi ne decodificherà il valore
REM in una stringa binaria, e lo mostrerà sullo schermo. Questo esempio inoltre mostra come
REM funziona lo scrolling verticale automatico, quando si raggiunge  con l'uso del comando 
REM ''PRINT'' la fine dello schermo.
REM
REM @include coleco,sg1000,sc3000,cpc,coco3

    CLS

    PRINT "+- BIT -+"
    PRINT "| 43210 |"
    PRINT "+-------+"
    PRINT "|       |"
    PRINT "+-------+"

i = 0
    DO
        j=JOY(0)
        LOCATE 2, 3
        PRINT BIN$(j,5)
        LOCATE 2, 5
        PRINT "T: ";i;"(";j;")"
        INC i
    LOOP
