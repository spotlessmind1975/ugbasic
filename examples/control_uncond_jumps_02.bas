100 REM @english
101 REM FLOW CONTROL WITH UNCONDITIONAL JUMPS (2)
102 REM
103 REM This example will show the use of ''GOTO'' keyword. The main code
104 REM will change the border color (yellow and black). Each color will last 100 milliseconds on the screen. 
105 REM The border color is changed using the ''COLOR BORDER'' instruction, using ''YELLOW'' and ''BLACK'' constants. 
106 REM To wait for a specific amount of time the ''WAIT'' command will be  used, with the ''MS'' (milliseconds) unit of time.
107 REM
108 REM @italian
109 REM CONTROLLO DI FLUSSO CON SALTI INCONDIZIONATI (2)
110 REM
111 REM Questo esempio mostrerà l'uso della parola chiave ''GOTO''. Il codice principale cambierà il colore 
112 REM del bordo (giallo e nero). Ogni colore durerà 100 millisecondi sullo schermo. Il colore del bordo viene cambiato 
113 REM usando l'istruzione ''COLOR BORDER'', usando le costanti ''YELLOW'' e ''BLACK''. Per attendere un 
114 REM determinato periodo di tempo verrà utilizzato il comando ''WAIT'', con l'unità di tempo ''MS'' (millisecondi).
115 REM
120 COLOR BORDER YELLOW
130 WAIT 100 MS
140 COLOR BORDER BLACK
150 WAIT 100 MS
160 GOTO 120