REM @english
REM OTHER CONTRIBUTIONS PRIME NUMBERS (4)
REM
REM This small example will extract the prime numbers between 2 and 400.
REM It has been taken and adapted by an exampled published on
REM RetroProgramming Italia's Facebook group.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI NUMERI PRIMI (4)
REM
REM Questo piccolo esempio estrarrà i numeri primi fra 2 e 400. Questo esempio 
REM è stato preso e adattato da uno pubblicato su Gruppo Facebook 
REM di RetroProgramming Italia.
REM
REM @url https://www.linkedin.com/pulse/ottimizzazione-del-codice-massimo-sanna/|"Ottimizzazione%20del%20codice"
REM
REM @include atari,atarixl,c128,c64,coco,cpc

4 CLS
5 REM inizializzo limite massimo e array di flag 
6 REM nums(x) = 0 -> x dentro
7 REM nums(x) = 1 -> x fuori
10 CONST maxn=400:DIM nums(maxn)
12 REM inizializzo timer e contatore di numeri primi
15 TI=0:np%=0
17 REM esamino tutti i numeri da 2 a maxn
20 FOR i=2 TO maxn
25 REM se il numero i è fuori dal crivello, passo al successivo
30 IF nums(i) <> 0 THEN : GOTO 90 : ENDIF
35 REM altrimenti i è primo. incremento contatore primi
36 REM stampo il primo i e mi preparo a generare i multipli
40 np%=np%+1:PRINT i,:k%=1
45 REM calcolo il multiplo come i*k (k=1,2,..)
46 REM finchè il multiplo è <= maxn
47 REM poi passo ad esaminare il prossimo i
50 multiplo=i*k%
60 IF multiplo>maxn THEN : GOTO 90 : ENDIF
70 REM metto il multiplo fuori dal crivello 
80 nums(multiplo)=1
82 REM calcolo il prossimo multiplo da escludere 
85 k%=k%+1:GOTO 50
90 NEXT
95 REM stampo il contatore dei numeri primi e il tempo trascorso 
100 REM PRINT:PRINT "contaprimi: ";np%
110 REM PRINT "ti ";TI
115 ct=(TI/60)
120 IF ct>60 THEN : ct=ct-60 : m%=m%+1 : GOTO 120 : ENDIF
130 PRINT:PRINT "time: ";m%;" min ";ct;" s"
140 PRINT CHR$(126);"(";c%;") =";np%