REM @english
REM OTHER CONTRIBUTIONS PRIME NUMBERS (3)
REM
REM This small example will extract the prime numbers between 2 and 400.
REM It has been taken and adapted by an exampled published on
REM RetroProgramming Italia's Facebook group.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI NUMERI PRIMI (3)
REM
REM Questo piccolo esempio estrarrà i numeri primi fra 2 e 400. Questo esempio 
REM è stato preso e adattato da uno pubblicato su Gruppo Facebook 
REM di RetroProgramming Italia.
REM
REM @url https://www.facebook.com/groups/retroprogramming/posts/793835291296728/|RetroProgramming%20Italia
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,sg1000,sc3000,cpc

0 CLS
1 c%=400:t=TI:m%=0:b%=3:PRINT " 2", " 3", " 5",
2 FOR i=7 TO c% STEP 2
3 maxj% = SQR(i)
4 FOR j=3 TO maxj% STEP 2: IF ( i MOD j ) == 0 THEN : GOTO 7 : ENDIF
5 NEXT
6 b%=b%+1:PRINT i,
7 NEXT
8 ct=(TI-t)/60
9 IF ct>60 THEN : ct=ct-60 : m%=m%+1 : GOTO 9 : ENDIF
10 PRINT:PRINT "time: ";m%;" min ";ct;" s"
11 PRINT CHR$(126);"(";c%;") =";b%
