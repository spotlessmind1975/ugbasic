REM @english
REM OTHER CONTRIBUTIONS GET/PUT PERFORMANCE
REM
REM This example attempts to calculate the speed of capturing 
REM and redrawing the ''GET IMAGE'' and ''PUT IMAGE'' primitives. The example is 
REM configurable to identify the weight of various factors 
REM in the operations.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI PERFORMANCE GET/PUT
REM
REM Questo esempio cerca di calcolare la velocità di cattura e 
REM ridisegno delle primitive ''GET IMAGE'' e ''PUT IMAGE''. 
REM L'esempio è configurabile per individuare il peso di vari 
REM fattori nelle operazioni.
REM
REM @include coco3,pc128op,to8

CONST width = 16
CONST height = 16

DIM timeLimit AS INTEGER

timeLimit = (TICKS PER SECOND) * 10

BITMAP ENABLE (16)
COLOR BORDER BLACK
CLS BLACK

VAR counter AS WORD = 0

LOCATE 0,0
PEN WHITE
PRINT "TESTING ON ";PEN(YELLOW);SCREEN WIDTH;"x";SCREEN HEIGHT;"x";SCREEN COLORS;PEN(WHITE)
PRINT "  FRAME : ";PEN(YELLOW);width;"x";height;PEN(WHITE)
PRINT "  DUR.  : ";PEN(YELLOW);(timeLimit / (TICKS PER SECOND));" secs";PEN(WHITE)
PRINT

background := NEW IMAGE(#width, #height)

TIMER = 0

DO
    GET IMAGE background FROM 0, 0
    PUT IMAGE background AT 0, 0
    INC counter
    EXIT IF TIMER > timeLimit
LOOP

PRINT "DONE"
PRINT

DIM fps AS FLOAT, frames AS FLOAT, time AS FLOAT
DIM pxs AS FLOAT, pixels AS FLOAT
px = 32 * 32
frames = counter
time = 10
pixels = px * frames

PRINT PEN(WHITE);" FRAMES   : "; frames
PRINT PEN(WHITE);" PIXELS   : "; pixels
PRINT PEN(WHITE);" FRAMES/S : "; PEN(YELLOW); INT( frames / time )

