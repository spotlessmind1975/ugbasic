REM TSB PROJECT USING CGOTO
REM
REM This example demonstrates the operation of the CGOTO command, which allows 
REM execution to continue at a position dynamically calculated at execution time, 
REM based on the value of an expression.
REM
REM @italian
REM PROGETTO TSB (ESEMPI) USANDO CGOTO
REM
REM Questo esempio mostra il funzionamento del comando CGOTO, che consente di 
REM continuare l'esecuzione a una posizione calcolata dinamicamente al momento 
REM dell'esecuzione, in base al valore di una espressione.
REM 
REM @include atari,atarixl,c128,c128z,c64,c64reu,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,sc3000,sg1000,to8,vg5000,vic20,zx

10 CLS
20 x = 3
30 CGOTO x*100
40 PRINT "really fails!": GOTO 20
100 PRINT "fails!": GOTO 20
200 PRINT "fails!": GOTO 20
300 PRINT "success!": GOTO 20

