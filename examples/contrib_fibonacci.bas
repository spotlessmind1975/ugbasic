REM @english
REM OTHER CONTRIBUTIONS FIBONACCI CALCULATION
REM
REM This example shows how to calculate the Fibonacci sequence using the classic BASIC approach. 
REM The Fibonacci sequence is defined by the following rules: the first two numbers are 1 and 1; 
REM each subsequent value is calculated by adding the two preceding values. The source limits 
REM the search to a maximum of a value of 5,000. 
REM
REM @italian
REM VARI ALTRI CONTRIBUTI CALCULATE FIBONACCI
REM 
REM Questo esempio mostra come calcolare la sequenza di Fibonacci utilizzando l'approccio BASIC
REM classico. La sequenza Fibonacci è definita dalle seguenti regole: i primi due numeri sono 
REM 1 e 1; ciascun valore successivo è calcolato sommando i due valori che lo precedono. Il sorgente
REM limita la ricerca a un massimo di un valore pari a 5.000.
REM
REM @include atari,atarixl,c128,c64,coco,d32,d64,coleco,cpc

10 CLS : HOME : max% = 5000
20 x% = 1 : y% = 1
30 IF (x% > max%) THEN 100
40 PRINT x%
50 x% = x% + y%
60 IF (y% > max%) THEN 100
70 PRINT y
80 y% = x% + y%
90 GOTO 30
100 END
