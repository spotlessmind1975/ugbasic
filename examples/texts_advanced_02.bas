REM @english
REM TEXTS OUTPUT VERTICAL SCROLL (USING VSCROLL)
REM
REM This example shows how to scroll a screen vertically: the program
REM clear the current screen, then locate to the position 10,10 and print ''"HELLO WORLD!"''.
REM Then, it first move the entire screen up of one line and, then, down of three lines.
REM
REM @italian
REM STAMPA DI TESTI CON SCROLLING (1)
REM
REM Questo esempio mostra come effettuare lo scorrimento verticale di un intero schermo.
REM Prima di tutto, il programma cancella lo schermo, si posiziona alla posizione 10,10 e
REM stampa la stringa ''"HELLO WORLD!''". Dopo di che, inizia a scorrere una riga verso l'alto
REM e, successivamente, tre righe verso il basso.
REM
REM @include atari

    CLS

    LOCATE 0,1
    PRINT "FIRST LINE!";

    LOCATE 10,10
    PRINT "HELLO WORLD!";

    LOCATE 10,10
    VSCROLL SCREEN UP
    WAIT 1000 MS
    VSCROLL SCREEN DOWN
    VSCROLL SCREEN DOWN
    VSCROLL SCREEN DOWN
    WAIT 1000 MS
