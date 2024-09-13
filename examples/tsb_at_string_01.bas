REM TSB PROJECT AT STRINGS
REM
REM This example will give an example of how AT command swaps two strings without 
REM creating string garbage that would eventually lead to garbage collection. 
REM AT works very quickly even with long and numerous strings, as no internal 
REM copying of the string contents is required. Only the string addresses are 
REM swapped.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) AT SU STRINGHE
REM
REM Questo esempio fornirà un esempio di come il comando AT scambia due stringhe 
REM senza creare stringhe temporanee, che alla fine porterebbero alla garbage 
REM collection. AT funziona molto rapidamente anche con stringhe lunghe e 
REM numerose, poiché non è richiesta alcuna copia interna del contenuto della 
REM stringa. Vengono scambiati solo gli indirizzi della stringa.
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

	CLS
	
	a$ = "Prima"
	b$ = "Dopo"
	
	AT(a$,b$)
	
	PRINT "Expected: Dopo Prima = ";a$;" ";b$
	

