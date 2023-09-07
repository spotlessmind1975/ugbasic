REM EXTERNAL INTEGRATION CALL MACHINE EXTERNAL MACHINE LANGUAGE FILE
REM 
REM This small example explains how to invoke external
REM machine language, loaded from a binary file and included
REM on the system. Note that, for each target, will be loaded
REM an assembled executable with the NOP opcode and a return
REM from call.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMARE CODICE MACCHINA DA FILE ESTERNO
REM
REM Questo piccolo esempio spiega come invocare codice
REM macchina esterno, caricato a sistema da un file binario. 
REM Da notare che, per ogni target, sarà caricato
REM un eseguibile assemblato con opcode NOP e un ritorno
REM dalla chiamata.
REM
REM @include atari,atarixl,c128,c64,coco,coleco

	CLS

	executable := LOAD("executable_nop.bin")

	address = VARPTR(executable)

	PRINT "External LM routine at $";
	PRINT HEX(address)

	PRINT "Calling LM routine: ";

	SYS address

	PRINT "OK!"
	
