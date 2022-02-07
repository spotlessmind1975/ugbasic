REM @english
REM OTHER CONTRIBUTIONS SIERPINSKI CHALLENGE (optimized)
REM
REM This example is the optimized version for the "Sierpinski Challenge",
REM an exciting challenge regarding fractals. This example reproduces the famous 
REM "SIERPINSKI TRIANGLE" on retrocomputers. It is a very simple fractal to obtain, 
REM which takes its name from the mathematician who first studied its properties.
REM Such a triangle can have different shapes and sizes and can be obtained in various
REM ways. One of the methods to create it is the so-called "Game of chaos". 
REM The fractal is built by creating iteratively a sequence of points, starting from
REM a random initial point, in which each point of the sequence is a given fraction 
REM of the distance between the previous point and one of the vertices of the polygon; 
REM the vertex is chosen at random in each iteration. Repeating this iterative process 
REM a large number of times, selecting the vertex at random at each iteration, often 
REM (but not always) produces a fractal shape. Using a regular triangle and the factor 1/2, 
REM it will result in a Sierpinski triangle.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI SIERPINSKI CHALLENGE (ottimizzato)
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

' ============================================================================
' INITIALIZATION
' ============================================================================

' We start measure time from the graphical initialization.
t=TI

' Enable the monocrome bitmap graphic, 
' with a minimum resolution of 160x100 pixels.
BITMAP ENABLE(320,200,2)

' Pen color is black
INK BLACK

' Paper color is white
CLS WHITE

' Let's calculate the three constants
CONST x1=(SCREEN WIDTH \ #2): CONST y1=0
CONST x2=0: CONST y2=(SCREEN HEIGHT - 1 )
CONST x3=(SCREEN WIDTH - 1): CONST y3=(SCREEN HEIGHT - 1 )

' Number of points to draw
CONST limit = 10000

' ============================================================================
' MAIN CYCLE
' ============================================================================

' Initialize the coordinates.
x=#x1:y=#y1

' Initialize the counter.
n=0

' Repeat the cycle up to (limit) points.
REPEAT

	' Select a random triangle
	r=(RANDOM BYTE \ 32) AND 3
	
	' If the triange has been chosen...
	IF r=0 THEN 
		' Update the coordinates accordingly.
		ADD x, x1 : DIV x, #2 
		ADD y, y1 : DIV y, #2 
	ELSE IF r=1 THEN 
		ADD x, x2 : DIV x, #2
		ADD y, y2 : DIV y, #2
	ELSE
		ADD x, x3 : DIV x, #2
		ADD y, y3 : DIV y, #2
	ENDIF
	
	' Plot the point on the screen.
	PLOT x, y

	' Increment the number of point traced.
	INC n

UNTIL n=limit

' Calculate the time passed
te=TI-t

HOME
' Print the stats
PRINT "time = ";(te/60);" sec"
PRINT "points = ";n
