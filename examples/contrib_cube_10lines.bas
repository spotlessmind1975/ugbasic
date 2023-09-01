REM @english
REM OTHER CONTRIBUTIONS 3D ROTATING CUBE
REM
REM This small example is the "10 lines" version of the rotating cube example. This example can be 
REM drawn in BASIC on various 8-bit home computers, using the same source.
REM
REM @italian
REM VARI ALTRI CONTRIBUTI ROTAZIONE 3D DI UN CUBO
REM
REM Questo piccolo esempio è la versione "10 lines" dell'esempio del cubo rotante. Questo esempio 
REM può essere disegnato in BASIC su vari computer domestici a 8 bit, utilizzando la stessa 
REM sorgente.
REM
REM @include atari

1BmEn(16):ClBl:Dit As8BIT:Diz As8BIT:Dip As8BIT(5),q As8BIT(5),x As8BIT(5),y As8BIT(5):Dia As8BIT=20:Dib As8BIT=20
2Dic As8BIT=70:Did As8BIT=45:Die As8BIT:Dif As8BIT:f=(b^2)/(a^2):e=c:bg:=NwIm(64,72):GeImbg Fm0,0:Foz=1Toa Stp2
3Fot=1To4:p(t)=x(t):q(t)=y(t):Nx:y(1)=SQR((b^2)-((z^2)*f)):x(4)=a-z:y(2)=SQR((b^2)-((x(4)^2)*f)):x(3)=-z:y(3)=-y(1)
4x(2)=-x(4):y(4)=-y(2):x(1)=z:PuImbg At32,24:Fot=1To4:u=(t An3):INCu:xt=x(t):xu=x(u):yt=y(t):yu=y(u):x1=xt+c:y1=yt+d
5x2=xu+c:y2=yu+d:Lnx1,y1 Tox2,y2,Wht:x2=xt+c:y2=yt+e:Lnx1,y1 Tox2,y2,Wht:y1=yt+e:x2=xu+c:y2=yu+e:Lnx1,y1 Tox2,y2,Wht
6Nx:Nx
