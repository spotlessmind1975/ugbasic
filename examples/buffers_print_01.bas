REM @english
REM BUFFERS MANAGEMENT PRINTING ON VIDEO
REM
REM This small example will show how to print a file, i.e.
REM loading it at compile time and printing on the screen. Note that
REM the additional keyboard BUFFER is needed, in order to explain
REM to ugBASIC that you want to print the content of the buffer
REM and not the kind of the variable.
REM 
REM @italian
REM GESTIONE DEI BUFFER STAMPA A VIDEO
REM
REM Questo piccolo esempio mostra come stampare a video un file,
REM caricandolo al momento della compilazione e stampandolo sullo schermo.
REM Da notare che la parola chiave BUFFER addizionale è necessaria,
REM per spiegare a ugBASIC che si vuole la stampa del contenuto del buffer
REM e non del tipo della variabile.
REM
REM @include atari,atarixl

    CLS

    b := LOAD("test2.txt")

    PRINT BUFFER b

