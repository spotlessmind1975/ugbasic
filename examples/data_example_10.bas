REM @english
REM EMBEDDED DATA USING READ END FUNCTION
REM
REM This small example will show how to use the ''READ END'' function.
REM We are using the ''READ SAFE'' variant.
REM 
REM @italian
REM INCLUDENDO DEI DATI USANDO L'ISTRUZIONE READ END
REM
REM Questo piccolo esempio mostra come usare la funzione ''READ END''.
REM In questo esempio usiamo la variante ''READ SAFE''.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

DIM a AS BYTE

DATA AS BYTE 42, 21, 10

DO
    READ a
    PRINT a;" ";
    WAIT KEY
    IF READ END THEN
        PRINT " end"
        RESTORE
    ENDIF
LOOP
