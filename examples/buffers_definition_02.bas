REM @english
REM BUFFERS MANAGEMENT LOADING FROM FILE (1)
REM
REM This small example will show how to load a file to define a buffer.
REM 
REM @italian
REM GESTIONE DEI BUFFER CON CARICAMENTO FILE (1)
REM
REM Questo piccolo esempio mostra la sintassi per caricare un file in un buffer.
REM

b = LOAD("examples/test.txt")

PRINT "b = ";b;" (";SIZE(b);" bytes)"

HALT
