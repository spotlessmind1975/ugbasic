REM @english
REM BUFFERS MANAGEMENT ALIASING ON FILE LOADING
REM
REM This small example will show the management of "aliasing",
REM i.e. when the same file is loaded more than once (currently,
REM it is loaded once, since the name is the very same).
REM 
REM @italian
REM GESTIONE DEI BUFFER ALIASING IN FASE DI CARICAMENTO
REM
REM Questo piccolo esempio mostra come viene gestito l'aliasing, cioè
REM quando viene chiesto di caricare lo stesso file (viene caricata una sola copia,
REM dato che il nome del file è lo stesso).
REM
REM @include atari

    CLS

    b = LOAD("test.txt")
    c = LOAD("test.txt")

    PRINT "b = ";b;" (";SIZE(b);" bytes)"
    PRINT "c = ";c;" (";SIZE(c);" bytes)"


