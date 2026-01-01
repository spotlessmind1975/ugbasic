REM @english
REM DEFINE PRAGMAS STACK POSITION AND SIZE (2)
REM
REM Although ugBASIC is a stackless language, it can still interact with 
REM the processor's stack. Not all processors allow you to change the 
REM size and position of the stack, and sometimes there are limitations 
REM due to hardware features (e.g., consoles). As with other instructions, 
REM ugBASIC's isomorphism still allows the instruction to be used on
REM processors that have a programmable stack.
REM 
REM @italian
REM PRAGMA E DEFINIZIONI POSIZIONE E DIMENSIONE STACK (2)
REM
REM Pur essendo ugBASIC un linguaggio stackless, è comunque in grado di 
REM interagire con lo stack presente nel processore. Non tutti i 
REM processori consentono di modificare la dimensione e la posizione dello
REM stack, e a volte sono presenti delle limitazioni, dettate dalle 
REM caratteristiche hardware (ad es. con le console): come accade con 
REM altre istruzioni, l'isomorfismo di ugBASIC consente comunque di
REM usare l'istruzione su quei processori che hanno uno stack 
REM programmabile.
REM
REM @include c128z,vz200

OPTION COMPILE ON C128Z,VZ200

	DEFINE STACK SIZE 100
	DEFINE STACK START &HFE82

PROCEDURE hello

	PRINT "hello!"

END PROCEDURE

	hello[]
	
