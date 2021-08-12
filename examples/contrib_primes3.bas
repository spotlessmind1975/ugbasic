REM @english
REM OTHER CONTRIBUTIONS PRIME NUMBERS (3)
REM
REM This small example has been taken and adapted by [[https://www.facebook.com/groups/retroprogramming/posts/793835291296728/|RetroProgramming Italia]].
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI NUMERI PRIMI (3)
REM
REM Questo piccolo esempio è stato preso ed adattato da [[https://www.facebook.com/groups/retroprogramming/posts/793835291296728/|RetroProgramming Italia]].
REM

1 c=1000:t=TI:m=0:b=3:PRINT " 2", " 3", " 5",
2 FOR i=7 TO c STEP 2
3 maxj = SQR(i)
4 FOR j=3 TO maxj STEP 2: IF ( i MOD j ) == 0 THEN : GOTO 7 : ENDIF
5 NEXT
6 b=b+1:PRINT i,
7 NEXT
8 ct=(TI-t)/60
9 IF ct>60 THEN : ct=ct-60 : m=m+1 : GOTO 9 : ENDIF
10 PRINT:PRINT "time: ";m;" min ";ct;" s"
11 PRINT CHR$(126);"(";c;") =";b