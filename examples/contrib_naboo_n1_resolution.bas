REM @english
REM OTHER CONTRIBUTIONS NABOO N1 STARFIGHTER (SCALED)
REM
REM This is a renderer for the data file produced by the converter from Blender Freestyle SVG 
REM (Scalable Vector Graphics) into sequential files. The file is stored on the host file
REM system, then loaded and used by ugBASIC to initialize the array. This example will render
REM a "Naboo N1 Starfighter", and a scaler is implemented, to guarantee that the image
REM will be drawn inside a "virtual screen" of 320x200 pixels.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI CACCIA STELLARE NABOO (SCALATO)
REM
REM Questo è un programma per riprodurre la grafica a partire dai dati prodotti dal convertitore 
REM da Blender Freestyle SVG (Scalable Vector Graphics) in file sequenziali. Il file viene 
REM memorizzato sul file system host, quindi caricato e utilizzato da ugBASIC per inizializzare 
REM l'array. Questo esempio renderizza "Naboo N1 Starfighter", e viene aggiunto uno scalatore,
REM per garantire the l'immagine sia disegnata all'interno di uno "schermo virtuale" di 320x200 pixel.
REM 
REM @url http://patsos.de/New_Weblog/?p=671
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000

	BITMAP ENABLE(320,200)

	RESOLUTION 300,200

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
