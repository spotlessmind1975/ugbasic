REM @english
REM OTHER CONTRIBUTIONS DRAWING SPOCK
REM
REM This is a renderer for the data file retrieved by BASIC Programming Language FB Group. 
REM The file (CSV) is stored on the host file system, then loaded and used by ugBASIC to 
REM initialize the array. This example will render Spock.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI DISEGNANDO SPOCK
REM
REM Questo è un renderer per il file di dati recuperato dal gruppo FB "BASIC Programming Language". 
REM Il file (CSV) viene archiviato nel file system host, quindi caricato e utilizzato da ugBASIC per
REM inizializzare l'array. Questo esempio disegnerà Spock.
REM 
REM @url https://www.facebook.com/groups/2057165187928233/posts/3494341764210561/
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,zx,pc128op,to8

	PROCEDURE example ON ALL BUT VIC20

		BITMAP ENABLE(320,200)

		CLS WHITE

		INK BLACK

		DIM data() = LOAD "spock.csv" AS TEXT READONLY

		DIM pos AS INTEGER = 0

		DO
		 	x1 = data(pos)  : y1 = data(pos+1) 
		 	x2 = data(pos+2): y2 = data(pos+3) 
		 	IF x1 = 999 THEN
		 		HALT
		 	ENDIF
		 	LINE x1, y1 TO x2, y2
		 	INC pos : INC pos : INC pos : INC pos
		LOOP

	END PROC

	example[] ON ALL BUT VIC20
