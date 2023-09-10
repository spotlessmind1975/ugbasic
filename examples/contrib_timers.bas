REM @english
REM OTHER CONTRIBUTIONS TIMERS!
REM
REM This small example will show how ''TI'' variable works.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI TIMERS!
REM
REM Questo piccolo esempio mostra come funziona la variabile ''TI''.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000,cpc

    TI = 0
    CLS
    DO
        HOME
        PRINT "TI = ";TI;" (";(TI/TICKS PER SECOND);" secs)"
    LOOP
