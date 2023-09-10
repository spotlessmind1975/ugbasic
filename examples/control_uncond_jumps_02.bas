REM @english
REM FLOW CONTROL USING GOTO WITH LINE NUMBERS
REM
REM This example will show the use of ''GOTO'' keyword. The main code
REM will change the border color (yellow and black). Each color will last 100 milliseconds on the screen. 
REM The border color is changed using the ''COLOR BORDER'' instruction, using ''YELLOW'' and ''BLACK'' constants. 
REM To wait for a specific amount of time the ''WAIT'' command will be  used, with the ''MS'' (milliseconds) unit of time.
REM
REM @italian
REM CONTROLLO DI FLUSSO USANDO GOTO CON NUMERI DI LINEA
REM
REM Questo esempio mostrerà l'uso della parola chiave ''GOTO''. Il codice principale cambierà il colore 
REM del bordo (giallo e nero). Ogni colore durerà 100 millisecondi sullo schermo. Il colore del bordo viene cambiato 
REM usando l'istruzione ''COLOR BORDER'', usando le costanti ''YELLOW'' e ''BLACK''. Per attendere un 
REM determinato periodo di tempo verrà utilizzato il comando ''WAIT'', con l'unità di tempo ''MS'' (millisecondi).
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000,cpc

120 COLOR BORDER YELLOW
125 HOME: PRINT "YELLOW"
130 WAIT 100 MS
140 COLOR BORDER BLACK
145 HOME: PRINT "BLACK "
150 WAIT 100 MS
160 GOTO 120