REM EXTERNAL INTEGRATION CALL EXTERNAL MACHINE LANGUAGE FILE (ABSOLUTE POSITION)
REM 
REM This small example explains how to invoke external
REM machine language, loaded from a binary file and included
REM on the system into a specific location. The external machine routine will receive
REM parameters from a specific register and store the result
REM on the same register.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMARE CODICE MACCHINA DA FILE BINARIO (POSIZIONE ASSOLUTA)
REM
REM Questo piccolo esempio spiega come invocare codice
REM macchina esterno, caricato a sistema da un file binario
REM in una locazione specifica.
REM La routine esterna riceverà il parametro da un registro
REM specifico e restituirà il risultato su un registro specifico.
REM
REM @include atari,atarixl,c128,c64

	CLS

	executable = LOAD("executable_increment.bin", 49152)
	address = VARPTR(executable)
	PRINT "External LM routine at $"; HEX(address)
	x = 0
	DO
		PRINT "x = "; x
		WAIT KEY
		SYS address WITH REG(B)=x RETURN x=REG(B) ON CPUZ80
		SYS address WITH REG(A)=x RETURN x=REG(A) ON CPU6809
		SYS address WITH REG(X)=x RETURN x=REG(X) ON CPU6502
		PRINT " *increment*"
	LOOP






