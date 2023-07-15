REM EXTERNAL INTEGRATION CALL MACHINE LANGUAGE IN BINARY FILE WITH RETURN VALUES
REM 
REM This small example explains how to invoke external
REM machine language, loaded from a binary file and included
REM on the system. The external machine routine will receive
REM parameters from a specific register and store the result
REM on the same register.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMARE CODICE MACCHINA SU FILE BINARIO CON RESTITUZIONE DI VALORI
REM
REM Questo piccolo esempio spiega come invocare codice
REM macchina esterno, caricato a sistema da un file binario.
REM La routine esterna riceverà il parametro da un registro
REM specifico e restituirà il risultato su un registro specifico.

	CLS
	
	executable := LOAD("executable_increment.bin")
	address = VARPTR(executable)
	x = 0
	DO
		SYS address WITH REG(B)=x RETURN x=REG(B) ON CPUZ80
		SYS address WITH REG(A)=x RETURN x=REG(A) ON CPU6809
		SYS address WITH REG(X)=x RETURN x=REG(X) ON CPU6502
		PRINT x
		WAIT KEY
	LOOP







