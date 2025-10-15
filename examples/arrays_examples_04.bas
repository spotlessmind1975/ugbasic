﻿REM @english
REM ARRAY MANAGEMENT ACCESSING (4)
REM
REM This small example will show how to change just a single element
REM of the array. This program shows both how to define a 
REM two-dimensional array and how to access the start and end elements 
REM of the array.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY ACCESSO (4)
REM
REM Questo piccolo esempio mostra come cambiare un singolo elemento 
REM dell'array. Questo programma mostra sia come definire un array 
REM bidimensionale che come accedere agli elementi iniziali e finali 
REM della matrice.
REM
REM @include atari,atarixl,c16,c128,c64,coco,cocob,coco3,coco3b,d32,d32b,d64,d64b,coleco,pc128op,to8,sg1000,sc3000,cpc,vic20,zx,pccga

    CLS

    DIM array AS BYTE (6,7)

    PRINT "array(0,0) = ";array(0,0)
    PRINT "array(5,0) = ";array(5,0)
    PRINT "array(0,6) = ";array(0,6)
    PRINT "array(5,6) = ";array(5,6)

    array(#5,#6) = 42

    PRINT

    PRINT "array(0,0) = ";array(0,0)
    PRINT "array(5,0) = ";array(5,0)
    PRINT "array(0,6) = ";array(0,6)
    PRINT "array(5,6) = ";array(#5,#6); " (exp. 42)"


