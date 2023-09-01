REM @english
REM OTHER CONTRIBUTIONS 3D ROTATING CUBE (2)
REM
REM This small example shows how a rotating cube can be drawn in BASIC on various 8-bit home computers, 
REM using the same source. Despite the fact that the rotation seems quite fast, the whole thing 
REM hasn't been optimized in the slightest. There are large possibilities for optimization of the code. 
REM
REM @italian
REM VARI ALTRI CONTRIBUTI ROTAZIONE 3D DI UN CUBO (2)
REM Questo piccolo esempio mostra come si può disegnare un cubo rotante in BASIC su vari home computer a 8 bit, 
REM Mutilizzando lo stesso sorgente BASIC. Nonostante il fatto che la rotazione sembri abbastanza veloce, il
REM tutto non è stato minimamente ottimizzato. Vi sono larghe possibiità di ottimizzazione del codice.
REM
REM @include atari

BITMAP ENABLE(16) : CLS BLACK
DIM t AS BYTE : DIM z AS BYTE
DIM p AS BYTE(5), q AS BYTE(5), x AS BYTE(5), y AS BYTE(5)
DIM a AS BYTE = 20: DIM b AS BYTE = 20: DIM c AS BYTE = 70
DIM d AS BYTE = 45: DIM e AS BYTE: DIM f AS BYTE
f=(b^2)/(a^2) : e=c
bg := NEW IMAGE(64,72)
GET IMAGE bg FROM 0,0
FOR z=1 TO a STEP 2
	FOR t=1 TO 4 : p(t)=x(t) : q(t)=y(t) : NEXT	
	y(1)=SQR((b^2)-((z^2)*f)) : x(4)=a-z
	y(2)=SQR((b^2)-((x(4)^2)*f)) : x(3)=-z
	y(3)=-y(1) : x(2)=-x(4)
	y(4)=-y(2) : x(1)=z
	PUT IMAGE bg AT 32, 24
	FOR t=1 TO 4
		u = (t AND 3) : INC u
		xt=x(t) : xu=x(u) : yt=y(t) : yu=y(u)
		x1=xt+c : y1=yt+d : x2=xu+c : y2=yu+d
		LINE x1,y1 TO x2,y2,WHITE
		x2=xt+c : y2=yt+e
		LINE x1,y1 TO x2,y2,WHITE
		y1=yt+e : x2=xu+c :	y2=yu+e
		LINE x1,y1 TO x2,y2,WHITE
	NEXT
NEXT


