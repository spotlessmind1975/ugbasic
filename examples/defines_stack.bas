REM @english
REM DEFINE PRAGMAS STACK POSITION AND SIZE (1)
REM
REM Although ugBASIC is a stackless language, it can still interact with 
REM the processor's stack. Not all processors allow you to change the 
REM size and position of the stack, and sometimes there are limitations 
REM due to hardware features (e.g., consoles). As with other instructions, 
REM ugBASIC's isomorphism still allows the instruction to be used on
REM processors that have a programmable stack.
REM 
REM @italian
REM PRAGMA E DEFINIZIONI POSIZIONE E DIMENSIONE STACK (1)
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
REM @include coco,cocob,coco3,coco3b,d32,d32b,d64,d64b,mo5,to8,zx

OPTION COMPILE ON COCO,COCOB,COCO3,COCO3B,D32,D64,D32B,D64B,MO5,PC128OP,TO8,ZX

	DEFINE STACK SIZE 100
	DEFINE STACK START &H7000

PROCEDURE hello

	PRINT "hello!"

END PROCEDURE

	hello[]
	
