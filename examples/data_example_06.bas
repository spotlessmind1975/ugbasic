REM @english
REM EMBEDDED DATA USING DATA LOAD
REM
REM This small example will show how to use the ''DATA LOAD'' instruction.
REM 
REM @italian
REM INCLUDENDO DEI DATI USANDO L'ISTRUZIONE DATA LOAD
REM
REM Questo piccolo esempio mostra come usare l'istruzione ''DATA LOAD''.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,to8,vg5000,vic20,zx

DATA "primo", "secondo"

DIM x AS STRING
DO
    READ x
    PRINT x
    WAIT KEY OR FIRE
    IF READ END THEN
        HALT
    ENDIF
LOOP
