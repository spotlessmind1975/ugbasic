REM EXTERNAL INTEGRATION CALL MACHINE LANGUAGE WITH REGISTERS
REM 
REM This small example explains how to invoke external
REM machine language, already present on the system,
REM passing a parameter on a specific CPU register.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMARE CODICE MACCHINA
REM
REM Questo piccolo esempio spiega come invocare codice
REM macchina esterno, già presente sul sistema, passando
REM un parametro in uno dei registri (A).

	SYS #49152 WITH REG(A)=#10
	 
	address = 49152
	first = 42
	second = 84
	
	SYS address WITH REG(A)=#10

