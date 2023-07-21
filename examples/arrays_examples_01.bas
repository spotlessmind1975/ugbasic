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
REM @exclude sc3000

	CLS
	
    DIM artist$(2), title$(2), year(2), price(2)

    artist$(0)="Cindy Lauper"
    title$(0)="Girls Just Want To Have Fun"
    year(0)=1983
    price(0)=10
    artist$(1)="David Bowie"
    title$(1)="Space Oddity"
    year(1)=1967
    price(1)=8

    PRINT title$(0) 
    PRINT price(0)
    PRINT title$(1) 
    PRINT year(1)
    PRINT price(1)

