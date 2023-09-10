REM @english
REM TEXTS OUTPUT TEXT POSITIONING (USING TAB$())
REM
REM This example shows the use of ''TAB$'' special var, that move the
REM cursor to the next tab mark. By using the ''SET TAB'' command, you
REM can change the position of tabs.
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (8)
REM
REM Questo esempio mostra l'uso della variabile speciale ''TAB$'', che sposta
REM il cursore al prossimo segno di tabulazione. Usando il comando ''SET TAB''
REM è possibile modificare la posizione dei tabs.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000,cpc

    CLS

    PRINT "0,0 HOME"
    PRINT TAB$;"0,1 AND"
    SET TAB 10
    PRINT TAB$;"TAB 10 AWAY"
