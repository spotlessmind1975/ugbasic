REM @english
REM TEXTS OUTPUT PRINT (WITH OPERATORS)
REM
REM This example shows the use of ''CDOWN'' function. The function will generate
REM a special sequence that will move the cursor to an absoute position. The
REM advantage of this method is that you can store a specific movement inside 
REM a string, and replay it by embedding a text.
REM
REM @italian
REM STAMPA DI TESTI CON POSIZIONAMENTO (10)
REM
REM Questo esempio mostra l'uso di ''CDOWN'', che incorpora un comando
REM in una stringa per spostare il cursore in basso di 1 carattere.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,pc128op,to8,cpc

    CLS

    PRINT "FOLLOW";"ON"
    PRINT "NEXT","TAB"
    PRINT "UGBASIC"
    PRINT "COMPILER"
    PRINT "UG";
    PRINT "BAS",
    PRINT "IC"
    