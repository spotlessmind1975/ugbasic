REM @english
REM STRING MANIPULATION GENERATE CHARACTER (USING CHR())
REM
REM This example print out a short list of printable characters.
REM
REM @italian
REM MANIPOLAZIONE DI STRIGHE CON L'USO DI CHR (1)
REM
REM Questo esempio stampa un breve elenco di caratteri stampabili.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,pc128op,to8,cpc

    CLS

    FOR i = 32 TO 256
      PRINT CHR(i);" ";
    NEXT
