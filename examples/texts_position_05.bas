REM @english
REM TEXTS OUTPUT TEXT POSITIONING (USING AT$())
REM
REM This example shows the use of ''AT'' function. The function will generate
REM a special sequence that will move the cursor to an absoute position. The
REM advantage of this method is that you can store a specific movement inside 
REM a string, and replay it by embedding a text.
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (5)
REM
REM Questo esempio mostra l'uso della funzione ''AT''. La funzione genererà
REM una sequenza speciale che sposterà il cursore in una posizione assoluta dello
REM schermo. Il vantaggio di questo metodo è che quello di poter memorizzare 
REM un movimento specifico all'interno di una stringa, e riprodurlo incorporandone il testo.
REM
REM @include atari,atarixl,c128

    CLS

    a=AT$(10,10)+"AT(10,10)"+AT$(2,4)+"AT(2,4)"+AT$(2,2)+"AT(2,2)"

    PRINT a
