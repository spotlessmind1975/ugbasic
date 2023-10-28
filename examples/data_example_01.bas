REM @english
REM EMBEDDED DATA USING DATA AND READ INSTRUCTION
REM
REM This small example will show the basic usage of the ''READ'' and
REM ''DATA'' instructions. In particular, we use the ''READ SAFE''
REM variant, in order to ignore the fact that the data are stored
REM in the compacted form.
REM 
REM @italian
REM INCLUDENDO DEI DATI USANDO LE ISTRUZIONI DATA E READ
REM
REM Questo piccolo esempio mostra l'uso di base delle istruzioni
REM ''READ'' e ''DATA''. In particolare, qui sarà utilizzata la
REM variante ''READ SAFE'', che consente di ignorare il fatto che
REM i dati sono memorizzati in formato compatto.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx

DATA 10, 100, 1000, 99

DO
    READ SAFE a
    PRINT a;" ";
    EXIT IF a = 99
LOOP