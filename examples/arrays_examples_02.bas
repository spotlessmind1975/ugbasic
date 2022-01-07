REM @english
REM ARRAY MANAGEMENT ACCESSING (1)
REM
REM This small example will show the basic syntax to define an array and to
REM accessing it.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY ACCESSO (1)
REM
REM Questo piccolo esempio mostra la sintassi base per definire un array e per
REM accedervi.
REM
REM @exclude coleco

    CONST elements = 100

    DIM vector(elements)

    vector(42) = 100

    PRINT "vector(42) = ";vector(42)
