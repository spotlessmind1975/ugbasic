REM @english
REM DEFINE PRAGMAS UNIQUE SCREEN MODE
REM
REM This small example will show how to limit the code generation
REM of the libraries to the screen mode selected.
REM 
REM @italian
REM PRAGMA E DEFINIZIONI MODALITA' SCHERMO UNICA
REM
REM Questo piccolo esempio mostra come limitare la generazione del
REM codice delle librerie alla modalità selezionata.
REM
REM @include atari,atarixl,c128

    DEFINE SCREEN MODE UNIQUE

    BITMAP ENABLE (16)

    CLS

    airplane1 := LOAD IMAGE("air_attack_airplane.png")
    airplane2 := LOAD IMAGE("air_attack_airplane.png" AS "airplanef") FLIP X

    PUT IMAGE airplane1 AT 0,0
    PUT IMAGE airplane2 AT 16,16
