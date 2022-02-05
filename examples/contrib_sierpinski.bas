REM @english
REM OTHER CONTRIBUTIONS SIERPINSKI CHALLENGE (adapted)
REM
REM This example is the optimized version for the "Sierpinski Challenge",
REM an exciting challenge regarding fractals. This example reproduces the famous "SIERPINSKI TRIANGLE" on the rear cars. It is a very simple fractal to obtain, which takes its name from the mathematician who first studied its properties. Such a triangle can have different shapes and sizes and can be obtained in various ways. One of the methods to create it is the
REM so-called "Game of chaos". The fractal is built by creating iteratively 
REM a sequence of points, starting from a random initial point, in which each point 
REM of the sequence is a given fraction of the distance between the previous point 
REM and one of the vertices of the polygon; the vertex is chosen at random in 
REM each iteration. Repeating this iterative process a large number of times, 
REM selecting the vertex at random at each iteration, often (but not always) 
REM produces a fractal shape. Using a regular triangle and the factor 1/2, 
REM it will result in a Sierpinski triangle.
REM
REM This source was adapted from the original published on [[https://www.facebook.com/groups/retroprogramming/posts/879754189371504/|Sierpinski Challenge]] on **RetroProgramming Italia - RP Italia**.
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI SIERPINSKI CHALLENGE (adattato)
REM
REM Questo esempio è la versione ottimizzata per la "Sierpinski Challenge", una
REM entusiasmante sfida che riguarda i frattali. Questo esempio riproduce sulle
REM retro-macchine il famoso "TRIANGOLO DI SIERPINSKI". Si tratta di un frattale
REM molto semplice da ottenere, che prende il nome dal matematico che per primo 
REM ne studiò le proprietà. Tale triangolo può avere forme e dimensioni diverse 
REM e può essere ottenuto in vari modi. Uno dei metodi per crearlo è il 
REM cosiddetto "Gioco del caos". Il frattale viene cioè costruito creando 
REM iterativamente una sequenza di punti, a partire da un punto casuale iniziale, 
REM in cui ogni punto della sequenza è una data frazione della distanza tra il 
REM punto precedente e uno dei vertici del poligono; il vertice è scelto a caso 
REM in ogni iterazione. Ripetendo questo processo iterativo un gran numero di
REM volte, selezionando il vertice a caso ad ogni iterazione, spesso (ma non 
REM sempre) si produce una forma frattale. Utilizzando un triangolo regolare e 
REM il fattore 1/2 si otterrà un triangolo di Sierpinski.
REM
REM Questo è il sorgente pubblicato e adattato, tratto da [[https://www.facebook.com/groups/retroprogramming/posts/879754189371504/|Sierpinski Challenge]] su **RetroProgramming Italia - RP Italia**.
REM

10 t=TI: REM POKE 53280,15
20 x1=160: y1=0
30 x2=0: y2=199
40 x3=319: y3=199
50 REM FOR k=0 TO 7999: POKE 40960+k,0: NEXT
55 BITMAP ENABLE(2)
60 REM POKE 53265,59: POKE 53272,24
65 CLS BLACK
70 REM FOR i=0 TO 999: POKE 1024+i,16: NEXT
80 x=x1:y=y1
90 r=RND(3)
100 IF r=0 THEN : x=(x+x1)/2: y=(y+y1)/2 : ENDIF
110 IF r=1 THEN : x=(x+x2)/2: y=(y+y2)/2 : ENDIF
120 IF r=2 THEN : x=(x+x3)/2: y=(y+y3)/2 : ENDIF
130 REM b=8*(x/8)+(y AND 7)+(y/8)*320+8192
140 REM POKE b,PEEK(b) OR (2^(7-(x AND 7)))
145 PLOT x, y, WHITE
150 n=n+1: IF n=3000 THEN : GOTO 170 : ENDIF
160 GOTO 90
170 te=TI-t: LOCATE 0, 22 : PRINT "elapsed time =";(te/60);"sec"
180 PRINT"number of plotted points =";n
190 REM POKE 53265,155: POKE 53272,21: POKE 53280,14
