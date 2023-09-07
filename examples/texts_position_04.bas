REM @english
REM TEXTS OUTPUT TEXT POSITIONING (USING CMOVE$())
REM
REM This example shows the use of ''CMOVE'' function. The function will generate
REM a special sequence that will move the cursor to a position that is relative
REM to the current one. The advantage of this method is that you can store
REM a specific movement inside a string, an replay it by embedding a text.
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (4)
REM
REM Questo esempio mostra l'uso della funzione ''CMOVE''. La funzione genererà
REM una sequenza speciale che sposterà il cursore in una posizione relativa a 
REM quella corrente. Il vantaggio di questo metodo è che quello di poter memorizzare 
REM un movimento specifico all'interno di una stringa, e riprodurlo incorporandone il testo.
REM
REM @include atari,atarixl,c128,c64,coco,coleco

    CLS

    PRINT CMOVE$(10,10);"CMOVE(10,10)"
