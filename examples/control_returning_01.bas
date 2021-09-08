REM @english
REM FLOW CONTROL WITH RETURNING (1)
REM
REM This example will show the use of ''GOSUB...RETURN'' keywords. The main code
REM will alternate the border colors, first yellow and after black. Each color
REM will last for one second on the screen. The color change routine is a separate
REM routine, called with ''GOSUB''. The border color is changed using the 
REM ''COLOR BORDER'' instruction, using the predefined constants ''YELLOW'' and 
REM ''BLACK''. To wait for a specific amount of time the ''WAIT'' command will be 
REM used, with the ''MS'' (milliseconds) unit of time.
REM
REM @italian
REM CONTROLLO DI FLUSSO CON RITORNO (1)
REM
REM Questo esempio mostrerà l'uso delle parole chiave ''GOSUB...RETURN''. Il codice 
REM principale alternerà i colori del bordo, prima giallo e poi nero. Ogni colore 
REM durerà per un secondo sullo schermo. La routine di cambio colore è una routine 
REM separata, chiamata con ''GOSUB''. Il colore del bordo viene modificato 
REM utilizzando l'istruzione ''COLOR BORDER'', utilizzando le costanti predefinite 
REM ''YELLOW'' e ''BLACK''. Per attendere un determinato periodo di tempo verrà 
REM utilizzato il comando ''WAIT'', con l'unità di tempo ''MS'' (millisecondi).
REM

start:
    GOSUB yellowBorder
    WAIT 1000 MS
    GOSUB blackBorder
    WAIT 1000 MS
    GOTO start

yellowBorder:
    COLOR BORDER YELLOW
    HOME: PRINT "YELLOW"
    RETURN

blackBorder:
    COLOR BORDER BLACK
    HOME: PRINT "BLACK "
    RETURN