REM @english
REM OTHER CONTRIBUTIONS NABOO N1 STARFIGHTER
REM
REM This is a renderer for the data file produced by the converter from Blender Freestyle SVG 
REM (Scalable Vector Graphics) into sequential files. The file is stored on the host file
REM system, then loaded and used by ugBASIC to initialize the array. This example will render
REM a "Naboo N1 Starfighter".
REM
REM @italian
REM VARI ALTRI CONTRIBUTI CACCIA STELLARE NABOO
REM
REM Questo è un programma per riprodurre la grafica a partire dai dati prodotti dal convertitore 
REM da Blender Freestyle SVG (Scalable Vector Graphics) in file sequenziali. Il file viene 
REM memorizzato sul file system host, quindi caricato e utilizzato da ugBASIC per inizializzare 
REM l'array. Questo esempio renderizza "Naboo N1 Starfighter".
REM 
REM @url http://patsos.de/New_Weblog/?p=671
REM
REM @include c128,coleco

	PROCEDURE example ON ALL BUT VIC20

		BITMAP ENABLE(320,200)

		CLS

		DIM data() = LOAD "contrib_naboo_n1.txt" AS TEXT READONLY

		DIM pos AS INTEGER = 0

		DO
			mode = data(pos): x = data(pos+1): y = data(pos+2)
			SELECT CASE mode
				CASE #0
					PLOT x, y
				CASE #1
					LINE TO x, y
				CASE ELSE
					HALT
			ENDSELECT
			
			INC pos : INC pos : INC pos
			
		LOOP

	END PROC

	example[] ON ALL BUT VIC20