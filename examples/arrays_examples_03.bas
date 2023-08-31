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
REM @include atari

    CLS
	
    CONST a = 6
    CONST b = 7
    CONST c = ( a*b ) / 2

    DIM ax AS BYTE WITH (3) (a,b)
    DIM ay AS BYTE WITH (3) (c)
    DIM az AS BYTE WITH (3) (c)

    PROCEDURE execute[t]
        
        SHARED ax, ay, az

        ax(ay(t),az(t)) = 0
        az(t) = az(t) + 1
        ax(ay(t),az(t)) = 1

    END PROCEDURE

    CALL execute[0]

    FOR y = 0 TO a-1
        FOR x = 0 TO b-1
            LOCATE x+1,y+1
            PRINT ax(x,y)
        NEXT
        PRINT
    NEXT    

