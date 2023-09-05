REM @english
REM TEXTS OUTPUT TEXT POSITIONING (USING LOCATE/CMOVE)
REM
REM This example shows the use of ''LOCATE'' AND ''CMOVE'' command.
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (7)
REM
REM Questo esempio mostra l'uso delle istruzioni ''LOCATE'' e ''CMOVE''.
REM
REM @include atari,atarixl,c128,c64

    CLS

    LOCATE 0,1
    CENTRE "0,1 AT CENTER"

    CMOVE ,3
    CENTRE "3 DOWN FROM 0,1"

