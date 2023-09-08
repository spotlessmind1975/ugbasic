REM @english
REM OTHER CONTRIBUTIONS MEMORY SCANNER
REM
REM This is the "10 liner" version of RAM-Scanner example. A RAM-scanner, written (originally) in XC=BASIC by the Italian JJ Flash, 
REM and translated in ugBASIC which displays part of the contents of the RAM, 
REM in PETSCII characters. With it you can run from one part of the retro computer 
REM memory to another by simply using the joystick. A nice example of how to take 
REM advantage of the powerful MMOVE instruction.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI SCANNER DI MEMORIA
REM
REM Questa è la versione "10 liner" dell'esempio di RAM-scanner. Un RAM-scanner scritto (originariamente) in XC=BASIC dallo sviluppatore JJ Flash e
REM tradotto in ugBASIC. Visualizza a video parte del contenuto della RAM, in caratteri PETSCII. 
REM Con esso ? possibile scorrazzare da una parte all'altra della memoria del retro computer
REM attraverso il direzionamento del joystick. Un bell'esempio di come sfruttare la potente 
REM istruzione MMOVE.
REM 
REM @url https://github.com/JJFlash-IT/XCB3_Examples/blob/main/RAM_Scan_XCB/xcb-ramscan.bas
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64

0IkWht:Cl:DO:Mmv w TO VdTxaSz(ScRws-1)*ScCms:Lc0,(ScRws-1):?w;"    ";
1j=Jy(0):k=Scc:IF(jHASBtLf)OR(k=KyA)Th:w=w-1:Ei:IF(jHASBtRg)OR(k=KyS)Th:w=w+1:Ei
2IF(jHASBtUP)OR(k=KyW)Th:w=w-80:Ei:IF(jHASBtDw)OR(k=KyZ)Th:w=w+80:Ei:Lp


