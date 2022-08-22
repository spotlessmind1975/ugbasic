REM @english
REM STORAGE MANAGEMENT LOADING A FILE
REM
REM This example shows how to load a file at runtime, comparing
REM to the fact of loading a file at compile time.
REM
REM @italian
REM MEMORIE DI MASSA CARICARE UN FILE
REM
REM Questo esempio mostra come caricare un file al momento dell'esecuzione,
REM comparato al caricamento al momento della compilazione.

STORAGE "DISCHETTO" AS "DISK1"
    FILE "examples/test.txt" AS "TEST"
ENDSTORAGE

textCompileTime := LOAD("examples/test.txt")
textCompileTimeAsString = (STRING) textCompileTime
textRunTimeAsString = DLOAD("TEST,P,R")

IF textCompileTimeAsString <> textRunTimeAsString THEN
    PRINT "TEST FAILED!"
ELSE
    PRINT "TEST OK!"
ENDIF

