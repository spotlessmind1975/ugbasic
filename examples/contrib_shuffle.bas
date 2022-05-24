REM @english
REM OTHER CONTRIBUTIONS SHUFFLING
REM
REM This small example will extract the first 1000 prime numbers.
REM More than worrying about generating random or pseudo-random 
REM numbers, it's interesting to generate non-repeating values. 
REM The purpose of this source is to verify the possibility of 
REM converting an algorithm for TI99 into ugBASIC.
REM
REM Original code by Francesco Ugga on [[https://www.facebook.com/groups/commodorevic20italia/posts/3156546024603317/?comment_id=3172768072981112|pubblicato qui]].
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI MESCOLAMENTO (SHUFFLING)
REM
REM Più che preoccuparsi di generare numeri casuali o pseudo casuali, 
REM è interessante generare valori non ripetuti. Lo scopo di questo
REM sorgente è verificare la possibilità di covertire un algoritmo
REM per TI99 in ugBASIC.
REM
REM Il codice originale di Francesco Ugga è [[https://www.facebook.com/groups/commodorevic20italia/posts/3156546024603317/?comment_id=3172768072981112|pubblicato qui]].
REM

100 RANDOMIZE
101 DIM cpc(6)
109 REM INTIALIZE ARRAY
110 FOR i = 0 TO 5
120 cpc(i) = i
130 NEXT
139 REM START SHUFFLING
140 FOR i = 5 TO 1 STEP -1
150 rndnumber = RND(i)
160 tmpnumber = cpc(i)
170 cpc(i) = cpc(rndnumber)
180 cpc(rndnumber) = tmpnumber
190 NEXT
200 PRINT cpc(0);cpc(1);cpc(2);cpc(3);cpc(4);cpc(5)
210 GOTO 110