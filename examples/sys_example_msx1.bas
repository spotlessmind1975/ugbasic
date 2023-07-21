REM EXTERNAL INTEGRATION SYSTEM CALLS (ON MSX)
REM 
REM This small example explains how to invoke MSX system 
REM functionalities. Please note that this is only an example, 
REM and that you need to have a good understanding of how the 
REM BIOS and BASIC works in order to use this functionality. 
REM In order for this example to work, it needs access to the 
REM import file invoked in the first line (IMPORT DECLARES). 
REM The file is located in the "/imports" folder, and is 
REM downloaded automatically by the IDE from version 1.14.1 onwards.
REM 
REM @italian
REM INTEGRAZIONE CODICE ESTERNO CHIAMATE DI SISTEMA (SU MSX)
REM
REM Questo piccolo esempio spiega come richiamare funzionalità 
REM di sistema dell'MSX. Si fa presente che questo è 
REM solo un esempio, e che è necessario avere una buona comprensione
REM di come funzioni il BIOS e il BASIC per poter utilizzare 
REM questa funzionalità. Per poter funzionare questo esempio ha 
REM necessità di accedere al file di importazione invocato nella 
REM prima riga (IMPORT DECLARES). Il file si trova nella cartella
REM "/imports" folder, e viene scaricato automaticamente dall'IDE 
REM a partire dalla versione 1.14.1 in poi.

IMPORT DECLARES

CLS

PRINT "---------------------"
PRINT "--- SYS EXAMPLE"
PRINT "---------------------"

PRINT "This example will"
PRINT "work only under MSX"

PROCEDURE example ON MSX1

	PRINT "Press any key..."

	DO
		c = chget[]
		PRINT "(key pressed!)"
	LOOP

END PROC

example[]



