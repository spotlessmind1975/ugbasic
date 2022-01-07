REM @english
REM ARRAY MANAGEMENT ACCESSING (2)
REM
REM This small example will show the basic syntax to define an array and to
REM accessing it.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY ACCESSO (2)
REM
REM Questo piccolo esempio mostra la sintassi base per definire un array e per
REM accedervi.
REM
REM @exclude coleco

    CONST a = 6
    CONST b = 7
    CONST c = ( a*b ) / 2

    DIM ax AS BYTE WITH (-1) (a,b)
    DIM ay AS BYTE WITH (-1) (c)
    DIM az AS BYTE WITH (-1) (c)

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
