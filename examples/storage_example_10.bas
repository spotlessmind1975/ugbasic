REM @english
REM STORAGE MANAGEMENT SAVING A FILE
REM
REM This example shows how to save a file at runtime.
REM
REM @italian
REM MEMORIE DI MASSA SALVARE UN FILE
REM
REM Questo esempio mostra come salvare un file al momento dell'esecuzione.
REM 
REM @include atari,atarixl,c128,c64,coco,coco3,vic20,cpc

CLS

DIM textSource AS STRING
DIM textDest AS STRING

textSource = "Tears in rain..."
textDest = " "
textDest = textDest + "                "

DSAVE "test.dat" FROM STRPTR(textSource) SIZE 16
DLOAD "test.dat" TO STRPTR(textDest)

INK WHITE
PRINT "SOURCE:"
PRINT textSource
PRINT "DEST:"
PRINT textDest
