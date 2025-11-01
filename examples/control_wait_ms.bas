REM @english
REM FLOW CONTROL WITH UNCONDITIONAL WAIT
REM
REM This example will show the use of ''WAIT...MS'' keyword. The main code
REM will print an blinking asterisk. Each symbol will last 1000 milliseconds
REM on the screen.
REM
REM @italian
REM CONTROLLO DI FLUSSO CON ATTESA INCONDIZIONATA
REM
REM Questo esempio mostrerà l'uso della parola chiave ''WAIT...MS''. Il codice principale 
REM stamperà un asterisco lampeggiante. Ogni simbolo durerà 1000 millisecondi
REM sullo schermo.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,cpc

    CLS

label: 
    HOME: PRINT "*"
    WAIT 1000 MS
    HOME: PRINT " "
    WAIT 1000 MS
    GOTO label
    