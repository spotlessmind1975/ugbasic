REM @english
REM OTHER CONTRIBUTIONS PRIME NUMBERS (2)
REM
REM This small example has been taken and adapted by [[https://www.facebook.com/groups/retroprogramming/posts/793835291296728/|RetroProgramming Italia]].
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI NUMERI PRIMI (2)
REM
REM Questo piccolo esempio è stato preso ed adattato da [[https://www.facebook.com/groups/retroprogramming/posts/793835291296728/|RetroProgramming Italia]].
REM

10 c=1000:t=TI:m=0:b=4:PRINT" 2", " 3", " 5", " 7", 
20 FOR i=11 TO c STEP 2
30 FOR j=5 TO SQR(i) STEP 6
40 IF ( i MOD j == 0 ) OR ( i MOD (j+2) == 0 ) THEN : GOTO 70 : ENDIF
45 IF i MOD 3 == 0 THEN : GOTO 70 : ENDIF
50 NEXT
60 b=b+1:PRINT i,
70 NEXT
80 ct=(TI-t)/60
90 IF ct>60 THEN : ct=ct-60 : m=m+1 : GOTO 90 : ENDIF
100 PRINT:PRINT"time: ";m;" min ";ct;" s"
110 PRINT CHR$(126);"(";c;") =";b
