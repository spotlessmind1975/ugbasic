REM @english
REM TEXTS OUTPUT WITH TABS (8)
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

    CLS
    PRINT "0,0 HOME"
    PRINT TAB$;"0,1 AND"
    SET TAB 10
    PRINT TAB$;"TAB 10 AWAY"

    HALT