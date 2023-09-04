REM @english
REM BUFFERS MANAGEMENT LOADING FROM FILE
REM
REM This small example will show how to load a file to define a buffer.
REM The file is loaded at compile time and included into the executable.
REM 
REM @italian
REM GESTIONE DEI BUFFER CON CARICAMENTO FILE
REM
REM Questo piccolo esempio mostra la sintassi per caricare un file in un buffer.
REM Il file è caricato al momento della compilazione, e incluso nell'eseguibile.
REM
REM @include atari,atarixl

    CLS

    b = LOAD("test.txt")

    PRINT "b = ";b;" (";SIZE(b);" bytes)"
