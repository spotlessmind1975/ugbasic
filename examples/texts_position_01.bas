REM @english
REM TEXTS OUTPUT TEXT POSITIONING (USING LOCATE)
REM
REM This example shows the use of ''LOCATE'' command to move the next output on the screen.
REM When omitting the parameters of the command, it means that that coordinate component
REM remains unaffected. 
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (1)
REM
REM Questo esempio mostra l'uso del comando ''LOCATE'' per sapostare la posizione dove
REM avverrà il successivo output sullo schermo. Quando si omettono i parametri del comando,
REM questo implica che quella specifica componente delle coordinate rimarrà inalterata.
REM
REM @include atari,atarixl,c128

    CLS

    PRINT "0,0"

    LOCATE 10,
    PRINT "STAY ON CURRENT LINE"

    LOCATE ,5
    PRINT "SIX FROM TOP"

    LOCATE 10,10
    PRINT "TEN DOWN AND TEN ACROSS"
