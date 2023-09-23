REM @english
REM ARRAY MANAGEMENT ACCESSING (1)
REM
REM This small example will show the basic syntax to define an array and to
REM accessing it. Note how arrays in ugBASIC start at zero. So if we dimension 
REM an array with the number 2 we mean an array of two elements: element 0 and element 1.
REM 
REM @italian
REM GESTIONE DEGLI ARRAY ACCESSO (1)
REM
REM Questo piccolo esempio mostra la sintassi base per definire un array e per
REM accedervi. Da notare come gli array, in ugBASIC, partono da zero. Quindi se dimensioniamo 
REM un array con il numero 2 stiamo intendendo un array di due elementi: l'elemento 0 e l'elemento 1.
REM
REM @include atari,atarixl,c128,c64,coco,coco3,d32,d64,coleco,sg1000,sc3000,cpc,vic20,zx

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


