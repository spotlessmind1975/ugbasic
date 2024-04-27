REM @english
REM ARRAY MANAGEMENT ACCESSING (3)
REM
REM This small example will show the basic syntax to define an array and to
REM accessing it. In this case we show how to define a two-dimensional array, 
REM initialized with a constant (3). It also shows how to allow a parametric 
REM procedure to access an array in the main program.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY ACCESSO (3)
REM
REM Questo piccolo esempio mostra la sintassi base per definire un array e per
REM accedervi. In questo caso si da conto di come definire un array a due 
REM dimensioni, inizializzato con una costante (3). Inoltre, si mostra come 
REM permettere l'accesso ad un array sul programma principale da parte di una 
REM procedura parametrica.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,pc128op,to8,sg1000,sc3000,cpc,vic20,zx

    CLS
	
    CONST first = 6
    CONST second = 7
    CONST third = ( first*second ) / 2

    DIM firstx AS BYTE WITH (3) (first,second)
    DIM firsty AS BYTE WITH (3) (third)
    DIM firstz AS BYTE WITH (3) (third)

    PROCEDURE execute[t]
        
        SHARED firstx, firsty, firstz

        firstx(firsty(t),firstz(t)) = 0
        firstz(t) = firstz(t) + 1
        firstx(firsty(t),firstz(t)) = 1

    END PROCEDURE

    CALL execute[0]

    FOR y = 0 TO a-1
        FOR x = 0 TO b-1
            LOCATE x+1,y+1
            PRINT firstx(x,y)
        NEXT
        PRINT
    NEXT    

