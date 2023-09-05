REM @english
REM DEFINE PRAGMAS USING DOUBLE BUFFER
REM
REM This small example will show how to limit the code generation
REM of the libraries when using double buffering
REM 
REM @italian
REM PRAGMA E DEFINIZIONI USO DOUBLE BUFFER
REM
REM Questo piccolo esempio mostra come limitare la generazione del
REM codice delle librerie quando si utilizza il double buffering.
REM
REM @include atari,atarixl,c128,c64

    DEFINE DOUBLE BUFFER ON

    BITMAP ENABLE (16)

    CLS

    airplane1 := LOAD IMAGE("air_attack_airplane.png")
    airplane2 := LOAD IMAGE("air_attack_airplane.png" AS "airplanef") FLIP X

    PUT IMAGE airplane1 AT 0,0
    PUT IMAGE airplane2 AT 16,16

