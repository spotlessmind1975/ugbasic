REM @english
REM HARDWARE CONFIGURATION CHANGE CARTRIDGE TYPE (TEST)
REM
REM With this example, it is possible to change the ROM cartridge 
REM type for the ColecoVision. This configuration takes place at 
REM compile time and cannot be changed while the program is running.
REM 
REM @italian
REM CONFIGURAZIONE DELL'HARDWARE MODIFICA DEL TIPO DI CARTUCCIA (TEST)
REM
REM Con questo esempio è possibile cambiare il tipo di cartuccia 
REM ROM per il ColecoVision. Questa configurazione avviene al 
REM momento della compilazione, e non può cambiare durante 
REM l'esecuzione del programma.
REM
REM @include coleco

OPTION COMPILE ON COLECO

CONFIGURE COLECO CARTRIDGE TEST

PRINT "HELLO WORLD!"
