REM EXTERNAL INTEGRATION CALL MACHINE LANGUAGE WITH REGISTERS
REM 
REM This small example explains how to invoke external
REM machine language, already present on the system,
REM passing a parameter on a specific CPU register. Note
REM that this code will not work since there is no
REM assembly code at that position.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMARE CODICE MACCHINA
REM
REM Questo piccolo esempio spiega come invocare codice
REM macchina esterno, già presente sul sistema, passando
REM un parametro in uno dei registri (A). Da notare che
REM questo codice non funzionerà dato che non c'è codice assembly
REM in quella posizione
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

	CLS

	SYS #49152 WITH REG(A)=#10
	 
	address = 49152
	first = 42
	
	SYS address WITH REG(A)=first

