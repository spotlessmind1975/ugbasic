REM @english
REM FONT SUPPORT REPLACE A CHAR
REM
REM This example will show how to replace a char
REM in the embedded (graphic) font.
REM
REM @italian
REM SUPPORTO AI FONT SOSTITUIRE UN CARATTERE
REM
REM Questo esempio mostrerà come sostituire un carattere
REM nel font (grafico) accluso.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,to8,plus4,sc3000,sg1000,vg5000,vic20,zx

    BITMAP ENABLE
    
    CLS

    DEFDGR(0) = $ff, $ff, $ff, $ff, $00, $00, $00, $00
    INK WHITE    
    PRINT "@"
