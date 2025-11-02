REM @english
REM BASIC COMMANDS SWAP NUMBERS
REM
REM This example shows how to exchange two variables of the same type.
REM 
REM @italian
REM COMANDI STANDARD BASIC SCAMBIO DI NUMERI
REM
REM Questo esempio mostra come scambiare tra loro due variabili dello stesso tipo.
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,to8,vg5000,vic20,zx

    CLS

    DIM firstbs AS SIGNED BYTE, secondbs AS SIGNED BYTE
    DIM firstbu AS BYTE, secondbu AS BYTE

	DIM firstws AS SIGNED WORD, secondws AS SIGNED WORD
    DIM firstwu AS WORD, secondwu AS WORD

	DIM firstds AS SIGNED DWORD, secondds AS SIGNED DWORD
    DIM firstdu AS DWORD, seconddu AS DWORD

    firstbs = -42: secondbs = 24
    firstbu = 42: secondbu = 24

	firstws = -4200: secondws = 2400
 	firstwu = 4200: secondwu = 2400

	firstds = -1024000: secondds = 204800
    firstdu = 1024000: seconddu = 204800
    
    SWAP firstbs, secondbs
    SWAP firstbu, secondbu

	SWAP firstws, secondws
 	SWAP firstwu, secondwu

	SWAP firstds, secondds
    SWAP firstdu, seconddu

	PRINT "BYTE SIGNED:";    
	IF firstbs = 24 THEN
		PRINT "OK (1) ";
	ELSE
		PRINT "FAIL (1) = ";firstbs
    ENDIF    
    IF secondbs = -42 THEN
		PRINT "OK (2) ";    
	ELSE
		PRINT "FAIL (2) = ";secondbs
    ENDIF

    PRINT
    
	PRINT "BYTE UNSIGNED:";    
    IF firstbu = 24 THEN
		PRINT "OK (1) ";
	ELSE
		PRINT "FAIL (2) = ";firstbu
    ENDIF
    IF secondbu = 42 THEN
		PRINT "OK (2) ";    
    ENDIF

    PRINT

	PRINT "WORD SIGNED:";    
	IF firstws = 2400 THEN
		PRINT "OK (1) ";
	ENDIF
	IF secondws = -4200 THEN
		PRINT "OK (2) ";	
	ENDIF
	
    PRINT
    
	PRINT "WORD UNSIGNED:";    
 	IF firstwu = 2400 THEN
		PRINT "OK (1) ";
 	ENDIF 	
 	IF secondwu = 4200 THEN
		PRINT "OK (2) ";
 	ENDIF

	PRINT

	PRINT "DWORD SIGNED:";    	
	IF firstds = 204800 THEN
		PRINT "OK (1) ";
	ENDIF
	IF secondds = -1024000 THEN
		PRINT "OK (2) ";
	ENDIF
	
	PRINT
	
	PRINT "DWORD UNSIGNED:";    	
    IF firstdu = 204800 THEN
		PRINT "OK (1) ";
    ENDIF
    IF seconddu = 1024000 THEN
		PRINT "OK (2) ";
    ENDIF
    
