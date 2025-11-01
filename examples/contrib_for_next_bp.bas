REM @english
REM OTHER CONTRIBUTIONS FOR...NEXT BEST PRACTICE
REM
REM This program will try to answer to the Gary Luckenbaugh's article
REM about FOR...NEXT best practice under ugBASIC.
REM
REM @url https://garyluckenbaugh.substack.com/p/basic-for-next-best-practices
REM 
REM @italian
REM VARI ALTRI CONTRIBUTI BEST PRACTICE FOR...NEXT
REM
REM Questo programma proverà a rispondere all'articolo di 
REM Gary Luckenbaugh sulle best practice nell'uso del FOR...NEXT.
REM
REM @url https://garyluckenbaugh.substack.com/p/basic-for-next-best-practices
REM
REM @include atari,atarixl,c128,c128z,c64,coco,coco3,coleco,cpc,d32,d64,mo5,msx1,pc128op,plus4,sc3000,sg1000,vg5000,vic20,zx,pc128op,to8

CLS

''' RULE #1
' Always enter a FOR-NEXT loop at the FOR. Don’t even think about entering 
' the middle of a loop. Not surprisingly, “there be dragons here” if you 
' do.
'
' In ugBASIC you can enter into a FOR...NEXT without problems.

PRINT "RULE#1"
PRINT

DIM x1 AS BYTE

x1 = 1

GOTO inTheMiddle1

FOR x1 = 1 TO 10

inTheMiddle1:

	PRINT x1;" ";
NEXT x1

PRINT

''' RULE #2
' Never leave a FOR-NEXT mid-flight. Use FOR-NEXT to count from the 
' beginning to the TO value with steps of STEP. If you feel you must 
' leave a FOR in mid-flight, then FOR is not the proper construct.
'
' In ugBASIC you can exit out from a FOR...NEXT without problems.

PRINT:PRINT "RULE #2"
PRINT

DIM x2 AS BYTE

FOR x2 = 1 TO 10

	PRINT x2;" ";
	
	IF x2 > 4 THEN GOTO outOfFor2
	
NEXT x2

outOfFor2:

PRINT

''' RULE #3
' If you absolutely must jump out of a FOR, then you must always 
' come back to where you left off. The best way to do this is 
' via GOSUB to jump out and then RETURN to where you were. 
' At the location where you jump out, there should be no 
' FORs with the same control variable, in this case i.
'
' In ugBASIC you can jump out using GOTO (see rules #1 and #2)
' and you can use the same variable if you jump inside a GOSUB.

''' RULE #4
' Never enter a FOR loop recursively, unless you are using a modern 
' BASIC, and even then use recursive subs/functions and not GOTOs 
' or GOSUBS
'
' ugBASIC does not support recursion

''' RULE #5
' Don’t try to change the final value or the step when a FOR-NEXT 
' is in-flight. You may get away with this on some BASICs and 
' not on others.
'
' In ugBASIC you can change initial, final and step value.

PRINT:PRINT "RULE #5"
PRINT

DIM x5 AS BYTE, f5 AS BYTE, t5 AS BYTE, s5 AS BYTE

f5 = 1: t5 = 10: s5 = 2

FOR x5 = f5 TO t5 STEP s5

	PRINT x5; " ";
	
	IF x5 > 4 THEN
		t5 = 10
		s5 = 4
	ENDIF
	
NEXT 

PRINT

''' RULE #6
' Don’t change the control variable in-flight:
'
' In ugBASIC you can change the contro variable, as you like.

PRINT:PRINT "RULE #6"
PRINT

DIM x6 AS BYTE

FOR x6 = 1 TO 10

	PRINT x6;" ";
	
	IF x6 > 3 THEN x6 = 10
		
NEXT 

PRINT

''' RULE #7
' Draw a line from each FOR to the corresponding NEXT, and make 
' sure no lines overlap, as depicted below:
'
'     +-- for i = 1 to 10
'     |
'+----|--------for j = 1 to 10
'+    |
'+    +---next i
'+
'+-------next j
'
' Also ugBASIC respects this rule.

