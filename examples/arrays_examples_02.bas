REM @english
REM ARRAY MANAGEMENT ACCESSING (2)
REM
REM This small example will show the basic syntax to define an array and to
REM accessing it. In this case we are defining an array whose size is defined
REM by means of a constant. Constants don't take up space, and make the source 
REM more readable.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY ACCESSO (2)
REM
REM Questo piccolo esempio mostra la sintassi base per definire un array e per
REM accedervi. In questo caso stiamo definendo un array la cui dimensione è 
REM definita per mezzo di una costante. Le costanti non occupano spazio, e 
REM rendono più leggibile il sorgente.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000,cpc,vic20,zx

    CLS

    CONST elements = 100

    DIM vector(elements)

    vector(42) = 100

    PRINT "vector(42) = ";vector(42)

