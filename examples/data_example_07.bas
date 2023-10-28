REM @english
REM EMBEDDED DATA USING DATA AND READ INSTRUCTION WITH EXPLICIT TYPE
REM
REM This small example will show the basic usage of the ''READ'' and
REM ''DATA'' instructions.
REM 
REM @italian
REM INCLUDENDO DEI DATI USANDO LE ISTRUZIONI DATA E READ CON TIPO ESPLICITO
REM
REM Questo piccolo esempio mostra l'uso di base delle istruzioni
REM ''READ'' e ''DATA''.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

DATA AS WORD 10, 100, 1000, 99

DO
    READ a
    PRINT a;" ";
    EXIT IF a = 99
LOOP