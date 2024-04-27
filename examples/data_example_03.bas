REM @english
REM EMBEDDED DATA USING RESTORE INSTRUCTION
REM
REM This small example will show how to use the ''RESTORE'' instruction.
REM 
REM @italian
REM INCLUDENDO DEI DATI USANDO L'ISTRUZIONE RESTORE
REM
REM Questo piccolo esempio mostra come usare l'istruzione ''RESTORE''.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,to8,vg5000,vic20,zx

first:
DATA 42, 21, 10

DO
    DO
        READ a
        PRINT a;" ";
        EXIT IF a = 99
    LOOP
    RESTORE second
LOOP

second:
DATA 1, 2, 3, 99
