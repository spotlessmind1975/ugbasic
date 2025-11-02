REM @english
REM EMBEDDED DATA USING DATA AND READ INSTRUCTION WITH LABELS
REM
REM This small example will show the usage of the READ and
REM DATA instructions when are located on different lines.
REM 
REM @italian
REM INCLUDENDO DEI DATI USANDO DATA E READ CON ETICHETTE
REM
REM Questo piccolo esempio mostra l'uso di base delle istruzioni
REM READ e DATA, in particolare quando le istruzioni sono
REM posizionate su linee differenti del progframma.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,to8,vg5000,vic20,zx

OPTION READ FAST

DIM a AS BYTE

first:
DATA AS BYTE 42, 21, 10

DO
    READ a
    PRINT a;" ";
    EXIT IF a = 99
LOOP

second:
DATA AS BYTE 1, 2, 3, 99
