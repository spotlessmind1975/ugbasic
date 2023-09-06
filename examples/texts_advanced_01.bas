REM @english
REM TEXTS OUTPUT HORIZONTAL SCROLLING (USING HSCROLL)
REM
REM This example shows how to scroll a line and a screen horizontally: the program
REM clear the current screen, then locate to the position 10,10 and print ''"HELLO WORLD!"''.
REM Then, it first move the written line to the left, then to the right. Then, all the screen
REM is first moved to the left and, then, to the right.
REM
REM @italian
REM STAMPA DI TESTI CON SCROLLING (1)
REM
REM Questo esempio mostra come effettuare lo scorrimento orizzontale, di una linea e di un intero
REM schermo. Prima di tutto, il programma cancella lo schermo, si posiziona alla posizione 10,10 e
REM stampa la stringa ''"HELLO WORLD!''". Dopo di che, inizia a scorrere prima la linea scritta
REM a sinistra, poi a destra. Quindi fa la stessa cosa con l'intero schermo, prima a sinistra e poi a destra.
REM
REM @include atari,atarixl,c128,c64,coco

    CLS
    LOCATE 10,10
    PRINT "HELLO WORLD!";

    WAIT 1000 MS

    LOCATE 10,10
    HSCROLL LEFT
    WAIT 1000 MS
    HSCROLL RIGHT
    WAIT 1000 MS

    HSCROLL SCREEN LEFT

    WAIT KEY
    
    WAIT 1000 MS
    HSCROLL SCREEN RIGHT
    WAIT 1000 MS
