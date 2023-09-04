REM @english
REM OTHER CONTRIBUTIONS 3D ROTATING CUBE
REM
REM This small example shows how a rotating cube can be drawn in BASIC on various 8-bit home computers, 
REM using the same source. Despite the fact that the rotation seems quite fast, the whole thing 
REM hasn't been optimized in the slightest. There are large possibilities for optimization of the code. 
REM
REM @italian
REM VARI ALTRI CONTRIBUTI ROTAZIONE 3D DI UN CUBO
REM
REM Questo piccolo esempio mostra come si può disegnare un cubo rotante in BASIC su vari home computer a 8 bit, 
REM Mutilizzando lo stesso sorgente BASIC. Nonostante il fatto che la rotazione sembri abbastanza veloce, il
REM tutto non è stato minimamente ottimizzato. Vi sono larghe possibiità di ottimizzazione del codice.
REM
REM @include atari,atarixl
 
BITMAP ENABLE(16) : CLS BLACK

DIM t AS BYTE : DIM z AS BYTE
DIM p AS POSITION(5), q AS POSITION(5), x AS POSITION(5), y AS POSITION(5)

a=20 : b=20 : f=(b^2)/(a^2) : c=70 : d=45  : e=c

buf := NEW IMAGE(64,72)
GET IMAGE buf FROM 0,0

FOR z=1 TO a STEP 1

	WAIT VBL
	
	PUT IMAGE buf AT 32, 24

	FOR t=1 TO 4 : p(t)=x(t) : q(t)=y(t) : NEXT	
	
	y(1)=SQR((b^2)-((z^2)*f)) : x(4)=a-z
	y(2)=SQR((b^2)-((x(4)^2)*f)) : x(3)=-z
	y(3)=-y(1) : x(2)=-x(4)
	y(4)=-y(2) : x(1)=z
	
	FOR t=1 TO 4
	
		u=t+1
		IF t=4 THEN : u=1 : ENDIF
		
		' SET LINE 0
		'x1=p(t)+c:y1=q(t)+d:x2=p(u)+c:y2=q(u)+d
		'LINE x1,y1 TO x2,y2,BLACK
		
		' SET LINE %1111111111111111
		x1=x(t)+c:y1=y(t)+d:x2=x(u)+c:y2=y(u)+d
		LINE x1,y1 TO x2,y2,WHITE

		' SET LINE 0
		'x1=p(t)+c:y1=q(t)+e:x2=p(u)+c:y2=q(u)+e
		'LINE x1,y1 TO x2,y2,BLACK
		
		' SET LINE %1111111111111111
		x1=x(t)+c:y1=y(t)+e:x2=x(u)+c:y2=y(u)+e
		LINE x1,y1 TO x2,y2,WHITE
		
		' SET LINE 0
		'x1=p(t)+c:y1=q(t)+d:x2=p(t)+c:y2=q(t)+e
		'LINE x1,y1 TO x2,y2,BLACK
		
		' SET LINE %1111111111111111
		x1=x(t)+c:y1=y(t)+d:x2=x(t)+c:y2=y(t)+e
		LINE x1,y1 TO x2,y2,WHITE
		
	NEXT
	
NEXT











