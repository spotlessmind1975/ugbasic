REM @english
REM EXTERNAL INTEGRATION SYSTEM CALLS (ON COMMODORE 64)
REM 
REM This small example explains how to invoke Commodore 64 system 
REM functionalities. Please note that this is only an example, 
REM and that you need to have a good understanding of how the 
REM KERNAL and BASIC works in order to use this functionality. 
REM In order for this example to work, it needs access to the 
REM import file invoked in the first line (IMPORT DECLARES). 
REM The file is located in the "/imports" folder, and is 
REM downloaded automatically by the IDE from version 1.14.1 onwards.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMATE DI SISTEMA (SU COMMODORE 64)
REM
REM Questo piccolo esempio spiega come richiamare funzionalità 
REM di sistema del Commodore 64. Si fa presente che questo è 
REM solo un esempio, e che è necessario avere una buona comprensione
REM di come funzioni il KERNAL e il BASIC per poter utilizzare 
REM questa funzionalità. Per poter funzionare questo esempio ha 
REM necessità di accedere al file di importazione invocato nella 
REM prima riga (IMPORT DECLARES). Il file si trova nella cartella
REM "/imports" folder, e viene scaricato automaticamente dall'IDE 
REM a partire dalla versione 1.14.1 in poi.

IMPORT DECLARES

CLS

PRINT "---------------------------------------"
PRINT "--- ugBASIC : SYS EXAMPLE C64"
PRINT "---------------------------------------"

PRINT "This example will work only "
PRINT "                     under Commodore 64"

PROCEDURE example ON C64

	PRINT "Press any key..."
	
	DO
		scnkey[]
		c = getin[]
		IF c <> 0 THEN
			PRINT "(key pressed!)"
		ENDIF
	LOOP
	
END PROC

example[] ON C64


