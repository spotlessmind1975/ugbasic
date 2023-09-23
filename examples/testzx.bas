`BITMAP ENABLE (160,200,16)
RESOLUTION 640,400
CLS
ORIGIN 0,400 UP

GLOBAL ciel,tankNumber,tankDroit,tankGauche,tankNumber,angle1,angle2
VAR boom AS IMAGE, ciel AS IMAGE, plancheSprite AS IMAGE

COLOR BORDER RGB(0,0,255)
plancheSprite := LOAD IMAGE("explosion_sprites.png")
PUT IMAGE plancheSprite AT 0,0 WITH TRANSPARENCY
`
