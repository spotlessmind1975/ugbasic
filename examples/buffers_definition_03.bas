REM @english
REM BUFFERS MANAGEMENT LOADING FROM FILE (2)
REM
REM This small example will show the management of "aliasing",
REM i.e. when the same file is loaded more than once (currently,
REM it is loaded once).
REM 
REM @italian
REM GESTIONE DEI BUFFER CON CARICAMENTO FILE (2)
REM
REM Questo piccolo esempio mostra come viene gestito l'aliasing, cioè
REM quando viene chiesto di caricare lo stesso file (viene caricata una sola copia).
REM

CLS

b = LOAD("test.txt")
c = LOAD("test.txt")

PRINT "b = ";b;" (";SIZE(b);" bytes)"
PRINT "c = ";c;" (";SIZE(c);" bytes)"

HALT

