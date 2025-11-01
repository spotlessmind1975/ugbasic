REM @english
REM STORAGE MANAGEMENT LOADING A FILE
REM
REM This example shows how to load a file at runtime.
REM
REM @italian
REM MEMORIE DI MASSA CARICARE UN FILE
REM
REM Questo esempio mostra come caricare un file al momento dell'esecuzione.
REM 
REM @include atari,atarixl,c128,c64,coco,coco3,vic20,cpc

CLS

STORAGE "DISCHETTO" AS "DISK1"
    FILE "test.txt" AS "test.dat"
ENDSTORAGE

DIM textRuntime AS STRING

textRuntime = "                "

DLOAD "test.dat" TO STRPTR(textRuntime) SIZE 16

INK WHITE
PRINT textRuntime

